# C++ Module 07 - Templates

Ce module introduit les templates de fonctions et de classes. Il montre comment écrire du code générique sans perdre en lisibilité ni en robustesse.

## Objectif du module

L'enjeu est de faire travailler le compilateur pour nous, en paramétrant le comportement d'un même code sur plusieurs types ou structures de données.

## Exercices

### ex00 - Whatever

Implémentation d'un échange générique entre deux valeurs, quel que soit leur type. L'exercice introduit le template de fonction et la notion de référence générique sur des données manipulables.

### ex01 - Iter

Application d'une fonction sur un tableau générique. L'intérêt est de séparer proprement l'algorithme de parcours de l'action appliquée à chaque élément.

### ex02 - Array

Création d'une classe template `Array` qui encapsule un tableau dynamique typé. Ce travail couvre la gestion de la taille, l'accès par indice et la copie correcte d'un conteneur générique.

## Compilation et exécution

Chaque exercice possède son `Makefile`.

```bash
make
./nom_du_programme
```

## Points d'attention

- Templates lisibles et bien isolés.
- Gestion correcte des accès hors limites.
- Copie et affectation conformes au comportement attendu.
- Code générique mais toujours simple à utiliser.
