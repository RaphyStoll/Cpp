# Notes d'implémentation - Account.cpp

## Analyse du fichier log

Le fichier log fourni (`CPP Module 00 Log Jan 4 1992.log`) a permis de comprendre le comportement attendu de chaque méthode.

### Format du timestamp
```
[YYYYMMDD_HHMMSS]
```
Implémenté avec `<ctime>` et `std::localtime()`.

### Comportements observés

#### 1. Constructeur
```
[timestamp] index:X;amount:Y;created
```
- Initialise `_accountIndex` avec la valeur actuelle de `_nbAccounts`
- Initialise `_amount` avec le dépôt initial
- Initialise `_nbDeposits` et `_nbWithdrawals` à 0
- Incrémente `_nbAccounts`
- Ajoute le dépôt initial à `_totalAmount`

#### 2. Destructeur
```
[timestamp] index:X;amount:Y;closed
```
- Affiche l'index et le montant final du compte
- Note : L'ordre des destructeurs peut varier (inverse de la création)

#### 3. displayAccountsInfos()
```
[timestamp] accounts:X;total:Y;deposits:Z;withdrawals:W
```
Affiche les statistiques globales de tous les comptes.

#### 4. displayStatus()
```
[timestamp] index:X;amount:Y;deposits:Z;withdrawals:W
```
Affiche le statut d'un compte individuel.

#### 5. makeDeposit()
```
[timestamp] index:X;p_amount:Y;deposit:Z;amount:W;nb_deposits:N
```
- `p_amount` = montant précédent
- `deposit` = montant du dépôt
- `amount` = nouveau montant (p_amount + deposit)
- `nb_deposits` = nombre total de dépôts pour ce compte

Met à jour :
- `_amount` (compte)
- `_nbDeposits` (compte)
- `_totalAmount` (global)
- `_totalNbDeposits` (global)

#### 6. makeWithdrawal()

**Succès :**
```
[timestamp] index:X;p_amount:Y;withdrawal:Z;amount:W;nb_withdrawals:N
```

**Échec (solde insuffisant) :**
```
[timestamp] index:X;p_amount:Y;withdrawal:refused
```

Vérifie que `withdrawal <= _amount` avant d'effectuer l'opération.

Si succès, met à jour :
- `_amount` (compte)
- `_nbWithdrawals` (compte)
- `_totalAmount` (global)
- `_totalNbWithdrawals` (global)

Retourne `true` en cas de succès, `false` en cas de refus.

## Forme canonique Orthodox

Bien que non strictement nécessaire pour cet exercice, la classe pourrait être étendue avec :
- Un constructeur de copie
- Un opérateur d'affectation

Ces éléments ne sont pas utilisés dans les tests mais respectent les bonnes pratiques C++98.

## Particularités C++98

- Utilisation de `std::time_t` et `std::tm*` pour les timestamps
- Utilisation de `std::setfill` et `std::setw` pour le formatage
- Pas de `nullptr` (C++11), utilisation de `NULL`
- Pas de liste d'initialisation moderne (C++11)
- Syntaxe classique des listes d'initialisation dans le constructeur

## Tests effectués

1. **Test officiel** (tests.cpp) : 8 comptes avec diverses opérations
2. **Tests personnalisés** (my_tests.cpp) : 3 comptes avec cas limites
3. **Scripts de vérification** :
   - `test.sh` : Comparaison automatique avec le log
   - `compare.sh` : Vérification des valeurs importantes

## Résultat

✅ Le programme produit une sortie identique au log fourni (sauf timestamp)
✅ Tous les tests passent
✅ Respect du standard C++98
✅ Respect des contraintes (pas de printf, alloc, free)
