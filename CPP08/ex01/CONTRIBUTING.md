# Directives du Projet : [Nom du Projet]

## 1. Règles Générales

- **Standard** : C++98 strictement.
- **Langue** : Commentaires en Français, code (variables, fonctions, classes) en Anglais.
- **Forme Canonique d'Orthodoxe** : Obligatoire pour chaque classe (Constructeur par défaut, constructeur de recopie, opérateur d'affectation, destructeur virtuel).

---

## 2. Normes de Code (Styleguide)

### Naming

- **Classes** : `UpperCamelCase` (ex: `MyClass`).
- **Fichiers de classe** : Suivre le nom de la classe (`MyClass.cpp` / `MyClass.hpp`).
- **Fichiers de méthodes/outils** : `snake_case.cpp`.
- **Variables privées** : Préfixe underscore `_` (ex: `_myVariable`).
- **Méthodes privées** : Préfixe underscore + PascalCase (ex: `_MyPrivateMethod`).
- **Méthodes publiques** : `PascalCase`.

### Organisation des fichiers

- Un `.hpp` et un `.cpp` principal par classe (contenant le canonique et la méthode run).
- **Règle des 8 méthodes** : Si une classe dépasse 8 méthodes, séparer les implémentations dans un dossier dédié (voir Architecture).
- **Structure interne du `.cpp`** : La méthode de classe en haut du fichier, les fonctions d'aide (static) en bas.

### Formatage des Accolades `{}`

- **Fonctions** : Accolade ouvrante sur une nouvelle ligne.
- **Structures de contrôle** (`if`, `else`, `while`) : Accolade ouvrante sur la même ligne.
- **Fermeture** : Jamais de `} else {`. L'accolade fermante doit être seule sur sa ligne.

---

## 3. Contraintes de Complexité & Métriques

- **Indentation (Style Kernel)** : Maximum 3 niveaux d'imbrication. Au-delà, extraction obligatoire dans une fonction static.
- **Taille des fonctions** : Maximum 40 lignes.
- **Nombre de fonctions par fichier** : Maximum 5 fonctions (1 méthode + 4 helpers static).
- **Logging** : Chaque classe inclut `libftpp::debug::DebugLogger _logger;`. Son utilisation est intensive mais ne compte pas dans les métriques de lignes ou d'indentation.
- **Généralisation (libftpp)** : Si une fonction static devient répétitive ou utile ailleurs, suggérer son déplacement dans la bibliothèque `libftpp`.

---

## 4. Architecture

### Dossiers

- `src/` : Tous les fichiers `.cpp`.
- `include/` : Tous les fichiers `.hpp` et `.tpp`.

### Gestion des Headers

- **Projets standards** : Gardes `#ifndef FILENAME_HPP`.
- **Librairies indépendantes** : `#pragma once`.

---

## 5. Préférences IA (Performance)

- **Mémoire** : Privilégier la Stack sur la Heap. Éviter `new` et `delete`.
- **Optimisation** : Toujours proposer l'approche la plus performante (CPU/Mémoire).
- **Passage d'arguments** : Utiliser systématiquement les références constantes `const T&` pour les types non-primitifs.

---

## Exemple de structure de fichier attendue

```cpp
#include "MyClass.hpp"

static bool helper_logic(int value);

void MyClass::ExecuteAction(int data)
{
    _logger.log("Execution de l'action");
    if (data != 0) {
        if (helper_logic(data)) {
            // Logique ici (max 3 niveaux)
        }
    }
}

static bool helper_logic(int value)
{
    if (value > 0) {
        return true;
    }
    return false;
}
```

