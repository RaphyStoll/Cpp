# Guide de Défense - Ex02 Account

## Présentation du projet (2-3 minutes)

### Contexte
"Bonjour ! Pour cet exercice, j'ai dû recréer un fichier `Account.cpp` qui avait été supprimé. J'avais à ma disposition :
- Le fichier header `Account.hpp` avec la déclaration de la classe
- Un fichier de log montrant la sortie attendue du programme
- Le fichier `tests.cpp` avec les tests à passer

Mon objectif était de recréer l'implémentation en analysant le comportement du programme à partir du log."

### Architecture de la solution
"J'ai structuré mon projet comme ceci :
- `src/Account.cpp` : L'implémentation de la classe Account
- `include/Account.hpp` : Le header fourni
- `src/tests.cpp` : Les tests officiels
- Un Makefile pour la compilation
- Des scripts de test pour vérifier la conformité"

## Démonstration (3-5 minutes)

### 1. Compilation
```bash
make
```
"La compilation passe sans warnings avec les flags -Wall -Wextra -Werror en C++98."

### 2. Exécution du test officiel
```bash
./account
```
"Comme vous pouvez le voir, le programme affiche exactement le même format que le log fourni."

### 3. Comparaison avec le log original
```bash
./compare.sh
```
"Ce script vérifie que toutes les valeurs numériques correspondent au log original, en ignorant seulement le timestamp qui est forcément différent."

### 4. Tests personnalisés
```bash
c++ -std=c++98 -Wall -Wextra -Werror src/my_tests.cpp src/Account.cpp src/utils/print_debug.cpp -Iinclude -o my_test
./my_test
```
"J'ai aussi créé des tests personnalisés pour vérifier les cas limites comme les retraits refusés."

## Questions fréquentes et réponses

### Q1: Comment as-tu analysé le fichier log ?

**Réponse :**
"J'ai procédé méthodiquement en identifiant chaque type d'opération dans le log :

1. **Création** : `[timestamp] index:X;amount:Y;created`
   - J'en ai déduit que le constructeur initialise l'index et le montant

2. **displayAccountsInfos** : `accounts:X;total:Y;deposits:Z;withdrawals:W`
   - Montre les variables statiques de classe

3. **makeDeposit** : `index:X;p_amount:Y;deposit:Z;amount:W;nb_deposits:N`
   - `p_amount` = previous amount, permet de voir que je dois afficher l'ancien montant avant de le modifier

4. **makeWithdrawal** : Deux cas possibles
   - Succès : `withdrawal:X;amount:Y;nb_withdrawals:N`
   - Échec : `withdrawal:refused`
   - J'en ai déduit qu'il faut vérifier le solde avant le retrait

5. **Destructeur** : `[timestamp] index:X;amount:Y;closed`

En comptant les lignes et vérifiant les valeurs, j'ai pu déduire l'ordre des opérations et leur logique."

### Q2: Pourquoi l'ordre des destructeurs est-il différent ?

**Réponse :**
"C'est normal et mentionné dans le sujet. Les destructeurs sont appelés dans l'ordre inverse de la construction, mais cet ordre peut varier selon le compilateur et le système d'exploitation. 

Dans le log original, on voit : 0, 1, 2, 3, 4, 5, 6, 7
Dans ma sortie : 7, 6, 5, 4, 3, 2, 1, 0

Les deux sont corrects. Ce qui compte, c'est que chaque destructeur affiche les bonnes informations pour son compte."

### Q3: Explique-moi les variables statiques

**Réponse :**
"Les variables statiques appartiennent à la classe, pas aux instances individuelles :

- `_nbAccounts` : Compte le nombre total de comptes créés
- `_totalAmount` : Somme de tous les montants de tous les comptes
- `_totalNbDeposits` : Nombre total de dépôts effectués
- `_totalNbWithdrawals` : Nombre total de retraits effectués

Elles doivent être initialisées en dehors de la classe :
```cpp
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
// etc.
```

Chaque fois qu'on crée un compte ou qu'on fait une opération, on met à jour ces variables."

### Q4: Comment fonctionne le timestamp ?

**Réponse :**
"J'utilise `<ctime>` qui est disponible en C++98 :

```cpp
void Account::_displayTimestamp(void) {
    std::time_t now = std::time(NULL);
    std::tm* ltm = std::localtime(&now);
    
    std::cout << "[";
    std::cout << (1900 + ltm->tm_year);
    std::cout << std::setfill('0') << std::setw(2) << (1 + ltm->tm_mon);
    // etc.
}
```

`tm_year` contient les années depuis 1900, donc j'ajoute 1900.
`tm_mon` va de 0 à 11, donc j'ajoute 1.
J'utilise `setfill('0')` et `setw(2)` pour avoir le format sur 2 chiffres."

### Q5: Pourquoi makeWithdrawal retourne un bool ?

**Réponse :**
"Le prototype dans le header indique `bool makeWithdrawal(int withdrawal)`.
En analysant le log, je vois que certains retraits sont refusés (withdrawal:refused).

Je retourne :
- `true` si le retrait est effectué (montant suffisant)
- `false` si le retrait est refusé (montant insuffisant)

Cela permet au code appelant de savoir si l'opération a réussi."

### Q6: Explique ton constructeur

**Réponse :**
"J'ai deux constructeurs :

1. **Constructeur avec paramètre** (public) :
```cpp
Account::Account(int initial_deposit)
    : _accountIndex(_nbAccounts),
      _amount(initial_deposit),
      _nbDeposits(0),
      _nbWithdrawals(0)
{
    _nbAccounts++;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    // affichage...
}
```
J'utilise la liste d'initialisation pour initialiser les membres.
L'index est assigné AVANT d'incrémenter _nbAccounts.

2. **Constructeur par défaut** (privé) :
Il est privé car on ne veut pas créer de compte sans dépôt initial."

### Q7: Comment gères-tu les dépôts et retraits ?

**Réponse :**
"Pour **makeDeposit** :
1. J'affiche le timestamp et l'état actuel (p_amount)
2. J'ajoute le dépôt au montant du compte
3. J'incrémente le compteur de dépôts du compte
4. Je mets à jour les variables statiques globales
5. J'affiche le nouvel état

Pour **makeWithdrawal** :
1. J'affiche le timestamp et l'état actuel
2. Je vérifie : `withdrawal > _amount` ?
   - Si oui : j'affiche 'refused' et retourne false
   - Si non : je soustrais, j'incrémente les compteurs, je mets à jour les globales
3. J'affiche le résultat"

### Q8: Forme canonique ?

**Réponse :**
"Bien que le sujet demande la forme canonique, elle n'est pas strictement nécessaire ici car on ne copie jamais de comptes.

Mais j'ai quand même :
- Constructeur(s) ✓
- Destructeur ✓
- Constructeur de copie (pourrait être ajouté)
- Opérateur d'affectation (pourrait être ajouté)

Si je devais les implémenter, je copierais tous les membres privés, mais c'est un cas d'usage discutable pour des comptes bancaires (devrait-on pouvoir copier un compte ?)."

### Q9: Contraintes C++98 respectées ?

**Réponse :**
"Oui, toutes :
- ✅ Pas de `nullptr` (j'utilise `NULL`)
- ✅ Pas de `auto`
- ✅ Pas de lambda
- ✅ Pas de range-based for loops
- ✅ Headers standards : `<iostream>`, `<ctime>`, `<iomanip>`
- ✅ Classes en UpperCamelCase (Account)
- ✅ Pas de `printf` (j'utilise `std::cout`)
- ✅ Pas d'`alloc`/`free` (gestion automatique)"

### Q10: Comment tester ton code ?

**Réponse :**
"J'ai créé plusieurs niveaux de tests :

1. **Test officiel** (`./account`) : Utilise tests.cpp fourni
2. **Tests personnalisés** (`./my_test`) : Cas limites et edge cases
3. **Script de vérification** (`./test.sh`) : Compare automatiquement avec le log
4. **Script de comparaison** (`./compare.sh`) : Vérifie les valeurs importantes

Tu peux aussi ajouter tes propres tests en créant des instances de Account."

## Points à mettre en avant

### 1. Méthodologie
"J'ai adopté une approche d'analyse forensique : partir du résultat attendu (le log) pour remonter à l'implémentation. C'est une compétence importante en debug et reverse engineering."

### 2. Tests rigoureux
"Je n'ai pas seulement fait fonctionner le test officiel. J'ai créé mes propres tests pour valider chaque comportement isolément."

### 3. Documentation
"J'ai documenté mes choix d'implémentation dans IMPLEMENTATION.md pour expliquer comment j'ai compris chaque méthode."

### 4. Respect des standards
"Code C++98 strict, compilation sans warnings, respect des conventions de nommage."

## Pièges à éviter

### ❌ Ne pas dire :
- "J'ai copié depuis Internet"
- "Je ne sais pas pourquoi ça marche"
- "J'ai essayé au hasard jusqu'à ce que ça passe"

### ✅ Dire plutôt :
- "J'ai analysé le log ligne par ligne"
- "J'ai compris que cette variable devait être statique car..."
- "J'ai testé avec différents cas pour valider ma compréhension"

## Commandes à connaître pour la démo

```bash
# Compilation
make

# Exécution
./account

# Nettoyage
make clean

# Recompilation
make re

# Tests personnalisés
./my_test

# Vérification
./compare.sh

# Voir le code
cat src/Account.cpp

# Compter les lignes
wc -l src/Account.cpp
```

## Timing de la défense

| Étape | Temps | Action |
|-------|-------|--------|
| Introduction | 1 min | Présenter le contexte de l'exercice |
| Démonstration | 2 min | Compiler et exécuter le programme |
| Explication du code | 5 min | Parcourir Account.cpp en expliquant |
| Tests | 2 min | Montrer les tests personnalisés |
| Questions | 5 min | Répondre aux questions de l'évaluateur |

## Conclusion

"Cet exercice m'a appris à :
- Analyser un comportement à partir de logs
- Utiliser les variables statiques de classe
- Gérer correctement l'état partagé et l'état d'instance
- Respecter rigoureusement un format de sortie
- Tester méthodiquement chaque fonctionnalité"

**Conseil final :** Reste calme, montre que tu comprends ce que tu as fait, et sois prêt à modifier le code en direct si l'évaluateur te le demande !
