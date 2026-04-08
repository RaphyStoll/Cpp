# C++ Module 06 - Casts explicites

Ce module se concentre sur les conversions de type en C++: `static_cast`, `dynamic_cast`, `reinterpret_cast` et `const_cast`.

## Objectif du module

Le but est de comprendre ce que chaque cast autorise réellement, quand il est pertinent de l'utiliser, et pourquoi il faut rester très strict sur les conversions implicites ou dangereuses.

## Exercices

### ex00 - Scalar conversion

Conversion d'une entrée texte vers plusieurs types scalaires. L'exercice demande de traiter les cas limites avec soin et de produire une sortie claire selon que la conversion est valide ou non.

### ex01 - Serialization

Travail sur la représentation mémoire d'un pointeur et sa transformation en entier, puis inversement. C'est un exercice pédagogique pour distinguer valeur, adresse et sérialisation triviale.

### ex02 - Identify

Identification d'un type concret à partir d'une base polymorphe. Le coeur du sujet est de comparer l'usage des conversions dynamiques via pointeur ou référence.

## Compilation et exécution

Chaque dossier contient son propre `Makefile`.

```bash
make
./nom_du_programme
```

## Points d'attention

- Choix du cast le plus adapté au besoin.
- Gestion explicite des cas impossibles.
- Sortie de conversion lisible et normalisée.
- Attention particulière aux cas indéfinis ou non portables.
