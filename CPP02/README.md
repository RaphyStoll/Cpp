# C++ Module 02 - Nombres à virgule fixe et surcharge d'opérateurs

Ce module introduit une idée centrale du C++: construire ses propres types numériques et leur donner un comportement naturel via la surcharge d'opérateurs.

## Objectif du module

Le but est de comprendre comment un type utilisateur peut imiter un type natif tout en gardant une représentation interne maîtrisée. On travaille aussi la forme canonique et les fonctions membres utiles pour manipuler ces objets.

## Exercices

### ex00 - My First Class in Orthodox Canonical Form

Première implémentation d'une classe simple en forme canonique orthodoxe. L'exercice met l'accent sur la discipline de construction, de copie et de destruction.

### ex01 - Towards a more useful fixed-point number class

Création d'un type `Fixed` qui stocke un nombre à virgule fixe. Le cœur du travail consiste à gérer une représentation entière interne et à exposer des conversions lisibles vers et depuis les types numériques classiques.

### ex02 - Now we're talking about operator overload

Évolution de la classe `Fixed` avec les opérateurs de comparaison, les opérateurs arithmétiques, ainsi que les formes préfixées et postfixées des incréments et décréments.

### ex03 - BSP

Exercice géométrique qui exploite la classe `Fixed` pour déterminer si un point appartient à un triangle. Il faut ici combiner calcul numérique et logique de test sans perdre en clarté.

## Compilation et exécution

Chaque exercice se compile indépendamment avec son propre `Makefile`.

```bash
make
./nom_du_programme
```

## Points d'attention

- Respect strict des conversions explicites.
- Surcharge d'opérateurs cohérente et intuitive.
- Gestion des arrondis et de la précision.
- Code pensé pour rester prévisible à la lecture.
