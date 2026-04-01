# C++ Module 08 - Templated Containers, Iterators, Algorithms

Ce module est dédié à l'apprentissage et l'utilisation de templates appliqués aux conteneurs de la STL, ainsi qu'aux itérateurs et algorithmes standards.

## Exercice 00: Easyfind 
- **Concept** : Templates de fonction et itérateurs de la STL.
- **Détails** : L'objectif était de créer la fonction template `easyfind` capable de chercher un entier dans n'importe quel conteneur de type T. Nous avons utilisé `std::find` venant de `<algorithm>`, qui permet de parcourir un conteneur via ses itérateurs `begin()` et `end()`. Si l'élément n'est pas trouvé (c'est-à-dire que `std::find` renvoie `end()`), une exception personnalisée est levée.

## Exercice 01: Span
- **Concept** : Classes, conteneurs, itérateurs et algorithmes STL avancés.
- **Détails** : Implémentation de la classe `Span`, capable de stocker jusqu'à $N$ entiers.
  - La méthode pour trouver la distance minimale (`shortestSpan`) consiste à trier une copie du vecteur généré, puis comparer itérativement chaque écart. L'utilisation d'une copie évite de modifier l'état interne de la classe.
  - Pour trouver la distance maximale (`longestSpan`), `std::min_element` et `std::max_element` sont utilisés sans qu'il soit nécessaire de trier au préalable.
  - La fonction `addNumber(Iterator, Iterator)` utilise les itérateurs. Nous vérifions d'abord la validité de la taille avec `std::distance()`, puis nous appelons `insert()`. 

## Exercice 02: Mutated abomination
- **Concept** : Classes adaptateurs et itérabilité.
- **Détails** : L'adaptateur `std::stack` masque le conteneur sous-jacent et le rend non-itérable (ce qui est le comportement standard LIFO). L'exercice requiert de développer une surcouche (`MutantStack`) qui hérite de `std::stack`.
Dans le standard C++, `std::stack` protègent leur conteneur interne sous `this->c`. Nous exposons ses itérateurs avec les "typedef" adéquats et les fonctions `begin()` et `end()` qui renvoient `this->c.begin()` et `this->c.end()`. 
