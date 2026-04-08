# C++ Module 00 - Premiers pas en C++

Ce premier module pose les bases du langage C++: compilation séparée, classes simples, manipulation des chaînes et entrée/sortie standard.

## Objectif du module

L'idée est de prendre en main le langage sans se reposer sur des automatismes issus du C. Les exercices sont volontairement courts, mais ils imposent déjà une discipline de structure, de lisibilité et de compilation propre.

## Exercices

### ex00 - Megaphone

Exercice d'initialisation autour de `argv` et des chaînes C. Le programme lit les arguments passés en ligne de commande et les transforme en majuscules. C'est un bon point d'entrée pour travailler la boucle principale, la gestion des caractères et les contraintes d'I/O.

### ex01 - PhoneBook

Mise en place d'un petit carnet d'adresses interactif. L'exercice introduit les classes, le stockage de données dans des objets et un affichage formaté. Le point important est de garder une interface claire entre la logique de gestion des contacts et la couche de présentation.

### ex02 - Account

Implémentation d'une classe bancaire à partir d'un log fourni. L'objectif est de reconstruire le comportement attendu à partir des traces, puis de respecter une sortie strictement formatée.

Le détail complet de cet exercice est documenté dans [CPP00/ex02/README.md](CPP00/ex02/README.md).

## Compilation et exécution

Chaque exercice possède son propre `Makefile`. En pratique, la séquence est toujours la même:

```bash
make
./nom_du_programme
```

## Points d'attention

- Respect strict du C++98.
- Utilisation minimale de la STL à ce stade.
- Sorties texte stables et lisibles.
- Code organisé pour rester simple à relire et à tester.
