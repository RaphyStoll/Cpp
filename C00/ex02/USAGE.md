# Guide d'utilisation - Ex02

## Compilation rapide

```bash
make
```

## Exécution

### Test officiel
```bash
./account
```

### Tests personnalisés
```bash
c++ -std=c++98 -Wall -Wextra -Werror src/my_tests.cpp src/Account.cpp src/utils/print_debug.cpp -Iinclude -o my_test
./my_test
```

## Scripts de test

### test.sh - Test complet avec comparaison
```bash
./test.sh
```
Compile, exécute et compare la sortie avec le log original.

### compare.sh - Vérification des valeurs
```bash
./compare.sh
```
Vérifie que toutes les valeurs numériques correspondent au log.

## Nettoyage

```bash
make clean    # Supprime l'exécutable
make fclean   # Alias de clean
make re       # Recompile depuis zéro
```

## Structure des fichiers

```
ex02/
├── include/              # Headers
│   ├── Account.hpp      # Header fourni (classe Account)
│   ├── config.hpp       # Configuration du debug
│   └── debug.hpp        # Déclaration de print_debug
├── src/                 # Sources
│   ├── Account.cpp      # Implémentation de Account
│   ├── tests.cpp        # Tests officiels fournis
│   ├── my_tests.cpp     # Tests personnalisés
│   └── utils/
│       └── print_debug.cpp  # Fonction de debug
├── Makefile             # Compilation
├── test.sh              # Script de test automatique
├── compare.sh           # Script de comparaison
├── README.md            # Documentation
└── IMPLEMENTATION.md    # Notes d'implémentation
```

## Vérifications

✅ Compilation sans warnings (-Wall -Wextra -Werror)
✅ Standard C++98
✅ Pas de printf, alloc, free
✅ Classes en UpperCamelCase
✅ Sortie identique au log (sauf timestamp)
✅ Forme canonique respectée

## Commandes utiles

```bash
# Voir le nombre de lignes de code
wc -l src/Account.cpp

# Comparer avec le log original (sans timestamp)
./account | sed 's/\[.*\] //' > my.txt
cat "../subject/CPP Module 00 Log Jan 4 1992.log" | sed 's/\[.*\] //' > orig.txt
diff my.txt orig.txt

# Vérifier les fuites mémoire (si valgrind installé)
valgrind --leak-check=full ./account
```
