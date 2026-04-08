# C++ Module 04 - Polymorphisme, abstractions et copies profondes

Ce module explore le polymorphisme dynamique, les classes abstraites et les conséquences concrètes de la copie d'objets contenant de la mémoire ou de l'état interne complexe.

## Objectif du module

L'objectif est de comprendre ce que signifie réellement remplacer un comportement à l'exécution, et pourquoi certains objets doivent être copiés profondément plutôt que simplement recopiés champ par champ.

## Exercices

### ex00 - Polymorphism

Premier contact avec le polymorphisme dynamique. L'exercice montre l'intérêt d'une méthode virtuelle et les limites d'un design sans destructeur virtuel.

### ex01 - I don't want to set the world on fire

Variation sur la hiérarchie précédente avec une gestion plus réaliste de la mémoire interne. Le point sensible est la copie correcte d'objets qui possèdent eux-mêmes des sous-objets.

### ex02 - Abstract class

Introduction aux classes abstraites et à l'instanciation par dérivation. Le but est de forcer une interface minimale commune tout en laissant les classes concrètes fournir le comportement effectif.

### ex03 - Interface and recap

Exercice de synthèse autour d'un système d'objets et d'une logique de création/gestion centralisée. Il mobilise les notions du module: polymorphisme, abstraction, copie, séparation des responsabilités.

## Compilation et exécution

Chaque exercice est autonome et possède son propre `Makefile`.

```bash
make
./nom_du_programme
```

## Points d'attention

- Méthodes virtuelles correctement déclarées.
- Destructeur virtuel sur les bases polymorphes.
- Copie profonde dès qu'un objet possède des ressources propres.
- Séparation nette entre interface et implémentation.
