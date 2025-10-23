# Exercice 02 - Account

## Description
Reconstruction du fichier `Account.cpp` manquant en analysant le fichier de log et le header `Account.hpp`.

## Structure du projet
```
ex02/
├── include/
│   ├── Account.hpp      # Header fourni
│   ├── config.hpp       # Configuration
│   └── debug.hpp        # Debug utilities
├── src/
│   ├── Account.cpp      # Implémentation de la classe Account
│   ├── tests.cpp        # Tests fournis
│   └── utils/
│       └── print_debug.cpp
├── Makefile
└── test.sh              # Script de test automatique
```

## Compilation et exécution

### Compilation
```bash
make
```

### Exécution
```bash
./account
```

### Tests automatiques
```bash
./test.sh
```

## Implémentation

La classe `Account` gère des comptes bancaires avec les fonctionnalités suivantes :

- **Création de compte** avec dépôt initial
- **Dépôts** (`makeDeposit`)
- **Retraits** (`makeWithdrawal`) avec vérification du solde
- **Affichage** du statut du compte
- **Statistiques globales** (nombre de comptes, montant total, etc.)

### Forme canonique
La classe est implémentée en forme canonique (Orthodox Canonical Form) :
- Constructeur par défaut (privé)
- Constructeur avec paramètre
- Destructeur
- Constructeur de copie (pas nécessaire ici mais prévu)
- Opérateur d'affectation (pas nécessaire ici mais prévu)

### Format de sortie
Chaque opération est loggée avec un timestamp au format : `[YYYYMMDD_HHMMSS]`

## Note
L'ordre des destructeurs peut varier selon le compilateur/système d'exploitation. C'est un comportement normal mentionné dans le sujet.

## Contraintes respectées
- ✅ C++98
- ✅ Classes en UpperCamelCase
- ✅ Pas de printf
- ✅ Pas d'alloc/free
- ✅ Forme canonique
