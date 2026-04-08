# C++ Module 01 - Pointeurs, références et mémoire

Ce module approfondit les bases du C++ en introduisant les pointeurs, les références, les allocations dynamiques et la gestion manuelle de petits objets métier.

## Objectif du module

L'enjeu est de comprendre ce qui se passe réellement en mémoire et de manipuler des objets avec plus de maîtrise. Les exercices demandent aussi de garder un code propre malgré des contraintes volontairement pédagogiques.

## Exercices

### ex00 - BraiiiiiiinnnzzzZ

Premier exercice autour de la création d'objets simples et de leur cycle de vie. Il sert surtout à vérifier que les constructeurs, destructeurs et appels de méthodes sont bien compris.

### ex01 - Moar brainz!

Extension du premier exercice avec une gestion en tableau dynamique de zombies. Le point central est la création d'objets à la volée, puis leur destruction propre une fois le travail terminé.

### ex02 - HI THIS IS BRAIN

Exercice court dédié aux pointeurs et aux références. Il sert à visualiser la différence entre adresse mémoire, valeur pointée et alias.

### ex03 - Unnecessary violence

Introduction à une petite hiérarchie de classes et à l'allocation dynamique d'objets. Le but est de manipuler des instances via des pointeurs sans perdre le contrôle de leur durée de vie.

### ex04 - Sed is for losers

Travail autour des fichiers, de la lecture/écriture et de la manipulation de texte. L'exercice renforce la pratique du flux I/O et des chaînes de caractères.

### ex05 - Harl 2.0

Implémentation d'un personnage bavard avec plusieurs niveaux de discours. L'exercice pousse à structurer la logique de sélection des comportements sans multiplier inutilement la duplication de code.

### ex06 - Harl filter

Filtrage des messages d'un objet selon un niveau de gravité. Le point important est de router proprement une entrée vers le bon traitement, tout en conservant une sortie cohérente.

## Compilation et exécution

Chaque sous-dossier contient son propre `Makefile`.

```bash
make
./nom_du_programme
```

## Points d'attention

- Gestion rigoureuse des allocations et libérations.
- Forme canonique quand elle est demandée.
- Utilisation contrôlée des références et des pointeurs.
- Sorties stables pour les exercices de texte.
