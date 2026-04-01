# C++ Module 09 - STL

Ce module met l'accent sur la maîtrise de l'utilisation de différents conteneurs de la STL. 
L'une des règles majeures de ce module est que chaque exercice doit utiliser **au moins un conteneur différent**, et les conteneurs sont exclusifs à chaque exercice.

## Exercice 00: Bitcoin Exchange
- **Concept** : Parsing, traitement de données, et manipulation de couples (Clé, Valeur). 
- **Conteneur choisi** : `std::map<std::string, float>`
- **Explications** : 
  L'exercice requiert de retrouver le prix du bitcoin à une date précise ou, à défaut, à la **date inférieure la plus proche**. Dans ce cas de figure, `std::map` prend tout son sens en C++ car la structure d'arbre binaire de recherche sous-jacente permet de trier automatiquement les dates sous forme de clés `std::string` lors de l'insertion (Format "YYYY-MM-DD").
  Pour trouver la date la plus proche inférieure, on utilise la méthode native `_database.lower_bound(date)`. Cette fonction retourne un itérateur très performant à la date voulue ou à la première date supérieure. Il suffit de reculer l'itérateur d'un cran (`--it`) si la date ne correspond pas de façon stricte.

## Exercice 01: Reverse Polish Notation
- **Concept** : Implémentation du système mathématique _Reverse Polish Notation_ (Post-fixe) et exécution linéaire.
- **Conteneur choisi** : `std::list<int>` exploitée comme une `std::stack` (Pile - LIFO).
- **Explications** : 
  La logique de l'algorithme RPN requiert d'empiler continuellement les nombres trouvés, et de les dépiler par paire (les deux derniers) chaque fois qu'un opérateur `+`, `-`, `*` ou `/` est croisé. 
  À la base `std::stack` est le meilleur choix car c'est un _Container Adaptor_ qui modélise nativement le Last-In-First-Out. Cependant, ayant interdiction formelle de pouvoir réutiliser le même type interne, j'ai implémenté notre propre pile logicielle via `std::list<int>`. 
  `std::list` offre les méthodes `push_back()` et `pop_back()`, accomplissant avec rigueur exactement l'objectif mathématique minimal requis de complexité `O(1)`. Si la pile ne possède pas exactement une et une seule valeur finale après l'itération totale, le programme se finit en "Error".
