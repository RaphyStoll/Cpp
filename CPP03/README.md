# C++ Module 03 - Héritage

Ce module introduit l'héritage simple et la réutilisation de code à travers une petite famille de classes orientées jeu de rôle.

## Objectif du module

L'objectif est de comprendre comment construire une hiérarchie de classes, spécialiser un comportement et conserver une base commune propre. C'est aussi le premier module où le partage d'état et de logique devient un sujet important.

## Exercices

### ex00 - ClapTrap

Création d'une classe de base représentant un personnage simple. L'exercice sert de socle pour les modules suivants et met en avant le cycle de vie de l'objet.

### ex01 - ScavTrap

Extension de `ClapTrap` avec des capacités spécifiques. On introduit ici la spécialisation d'une classe dérivée et la réutilisation des champs et méthodes de la classe mère.

### ex02 - FragTrap

Nouvelle variante de `ClapTrap` avec ses propres caractéristiques. L'enjeu est de conserver une logique commune tout en adaptant les valeurs et comportements propres à la classe dérivée.

### ex03 - DiamondTrap

Exercice de synthèse qui combine plusieurs aspects des classes précédentes. Il faut gérer correctement les identités, les capacités héritées et les ambiguïtés liées à une hiérarchie plus riche.

## Compilation et exécution

Chaque dossier d'exercice dispose de son propre `Makefile`.

```bash
make
./nom_du_programme
```

## Points d'attention

- Construction correcte des chaînes d'héritage.
- Appel explicite des constructeurs et destructeurs quand nécessaire.
- Éviter les duplications de logique entre classes parentes et filles.
- Conserver une sortie lisible pour faciliter les tests.
