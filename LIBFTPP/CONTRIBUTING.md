# Directives du Projet : libftpp

Bibliothèque d'utilitaires C++98 personnelle et réutilisable.

---

## 1. Règles Générales

- **Standard** : C++98 strictement (compatibilité maximale avec les systèmes legacy et projets académiques).
- **Langue** : Commentaires et documentation en Français, code (variables, fonctions, classes, namespaces) en Anglais.
- **Forme Canonique d'Orthodoxe** : Obligatoire pour chaque classe (Constructeur par défaut, constructeur de recopie, opérateur d'affectation, destructeur).
- **STL C++98** : Utilisation libre de tous les containers et algorithmes standards (`<algorithm>`, `<vector>`, `<map>`, `<list>`, etc.). Privilégier les approches idiomatiques C++98.

---

## 2. Normes de Code (Styleguide)

### Naming

- **Namespaces** : `snake_case` ou `lowercase` (ex: `libftpp::debug`, `libftpp::str`, `libftpp::net`).
- **Classes** : `UpperCamelCase` (ex: `StringUtils`, `DebugLogger`, `Buffer`).
- **Fichiers** : Suivre le nom de la classe/module (ex: `StringUtils.cpp` / `StringUtils.hpp`).
- **Variables privées** : Préfixe underscore `_` (ex: `_buffer`, `_filename`).
- **Méthodes privées** : Préfixe underscore + PascalCase (ex: `_CompactBuffer`).
- **Méthodes publiques** : `camelCase` ou `PascalCase` selon le contexte (ex: `trim()`, `ltrim()`, `toLower()`).
- **Fonctions helper static** : `snake_case` en privé dans les `.cpp` (ex: `is_space()`, `to_lower()`).

### Organisation des fichiers

- **Un module = un header + un .cpp** (ex: `StringUtils.hpp` + `StringUtils.cpp`).
- **Header principal** : `libftpp.hpp` inclut tous les modules.
- **Templates** : Implémentation directement dans le `.hpp` (ou `.tpp` si séparé).
- **Structure interne du `.cpp`** :
  - Méthodes publiques en haut.
  - Fonctions helper `static` privées en bas.

### Gestion des Headers

- **`#pragma once`** : Privilégié pour sa simplicité (compatible avec tous les compilateurs modernes).
- **Includes** : 
  - Dans les `.cpp` : Includes relatifs (`../include/Module.hpp`) pour indépendance des flags de compilation.
  - Dans les `.hpp` : Includes absolus si la lib est installée, sinon relatifs.
- **Forward declarations** : Utiliser quand possible pour réduire les dépendances et accélérer la compilation.

### Formatage des Accolades `{}`

- **Fonctions** : Accolade ouvrante sur une nouvelle ligne.
- **Structures de contrôle** (`if`, `else`, `while`, `for`) : Accolade ouvrante sur la même ligne.
- **Fermeture** : Jamais de `} else {`. L'accolade fermante doit être seule sur sa ligne.

---

## 3. Bonnes Pratiques & Recommandations

- **Indentation** : Limiter l'imbrication à 3 niveaux maximum pour la lisibilité. Au-delà, considérer l'extraction dans une fonction helper.
- **Taille des fonctions** : Viser ~40 lignes par fonction. Les fonctions plus longues doivent rester claires et bien structurées.
- **Cohésion** : Si une classe devient trop volumeuse (>10-12 méthodes publiques), envisager de la découper en modules séparés.
- **Macros** : Éviter les macros complexes. Préférer les fonctions `inline`, les templates, ou les constantes `const`/`enum`.

---

## 4. Architecture & Modules

### Structure des dossiers

```
LIBFTPP/
├── include/          # Tous les .hpp
│   ├── libftpp.hpp   # Header principal (inclut tout)
│   ├── debug.hpp
│   ├── StringUtils.hpp
│   ├── Buffer.hpp
│   └── ...
├── src/              # Tous les .cpp
│   ├── StringUtils.cpp
│   ├── Buffer.cpp
│   └── ...
├── obj/              # Fichiers objets (.o)
│   ├── static/
│   └── shared/
├── tests/            # Tests unitaires
├── Makefile
└── CONTRIBUTING.md
```

### Organisation par namespaces

Chaque module doit être dans un namespace dédié :

```cpp
namespace libftpp {
namespace str {
    class StringUtils { ... };
}
}
```

Namespaces principaux :
- `libftpp::str` : Utilitaires pour les chaînes (`StringUtils`).
- `libftpp::debug` : Outils de debug et logging (`DebugLogger`).
- `libftpp::net` : Réseau et sockets (`Fd`, helpers réseau).
- `libftpp::Buffer` : Gestion de buffers (`Buffer`).
- Autres selon les besoins (ex: `libftpp::http`, `libftpp::path`).

### Classes utilitaires statiques

Pour les modules d'utilitaires purs (pas d'état), utiliser une classe avec :
- Constructeurs privés (non instanciable).
- Méthodes `static` publiques uniquement.

```cpp
class StringUtils {
private:
    StringUtils() {};
    StringUtils(const StringUtils& other) { (void)other; };
    StringUtils& operator=(const StringUtils& other) { 
        (void)other; 
        return *this; 
    };
    ~StringUtils() {};

public:
    static std::string trim(const std::string& s);
    static std::string ltrim(const std::string& s);
    // ...
};
```

### Classes RAII

Pour les ressources (fichiers, sockets, mémoire), utiliser le pattern RAII :
- Acquisition dans le constructeur.
- Libération dans le destructeur.
- Interdire la copie si nécessaire (copie privée).

```cpp
class Fd {
private:
    int _fd;
    Fd(const Fd& other);              // Non copiable
    Fd& operator=(const Fd& other);   // Non assignable

public:
    Fd();
    explicit Fd(int fd);
    ~Fd();  // Ferme automatiquement
    // ...
};
```

---

## 5. Documentation

### Commentaires de documentation

Utiliser le style Doxygen pour toutes les méthodes publiques :

```cpp
/**
 * @brief Retire les espaces au début et à la fin d'une chaîne
 * @param s La chaîne à traiter
 * @return Une nouvelle chaîne sans espaces aux extrémités
 */
static std::string trim(const std::string& s);
```

### Commentaires internes

- **Français** pour les commentaires explicatifs dans le code.
- **Concis** : Expliquer le "pourquoi", pas le "quoi" (sauf si complexe).

---

## 6. Préférences & Optimisation

### Mémoire

- **Stack > Heap** : Privilégier la Stack. Éviter `new` et `delete`.
- **RAII** : Pour toute ressource système (fd, malloc, etc.).
- **Pas de fuites** : Tester avec `valgrind` ou équivalent.

### Passage d'arguments

- **Types primitifs** (`int`, `char`, `bool`, etc.) : Par valeur.
- **Types non-primitifs** (`std::string`, `std::vector`, etc.) : Par référence constante `const T&`.
- **Retour** : Par valeur (RVO/NRVO s'applique en C++98).

### Optimisation

- **Éviter les copies inutiles** : Utiliser `.reserve()` pour `std::vector` et `std::string` quand la taille est connue.
- **Éviter les allocations répétées** : Réutiliser les buffers quand possible.
- **Complexité** : Documenter la complexité algorithmique si non-triviale (O(n), O(n²), etc.).

---

## 7. Tests & Validation

### Tests unitaires

- Créer un fichier de test pour chaque module dans `tests/`.
- Tester les cas normaux ET les cas limites (chaîne vide, NULL, overflow, etc.).

### Compilation

```bash
make              # Compile la bibliothèque statique (.a)
make shared       # Compile la bibliothèque partagée (.so / .dylib)
make clean        # Nettoie les .o
make fclean       # Nettoie tout (lib + .o)
make re           # Recompile tout
```

### Flags de compilation

- **Standard** : `-std=c++98`
- **Warnings** : `-Wall -Wextra -Werror`
- **Optimisation** : `-O2` pour la production (optionnel)
- **Debug** : `-g -DDEBUG` pour activer les logs

---

## 8. Ajout d'un nouveau module

### Checklist

1. Créer `include/ModuleName.hpp` :
   - `#pragma once` en haut.
   - Namespace approprié (`libftpp::xxx`).
   - Documentation Doxygen pour chaque méthode publique.

2. Créer `src/ModuleName.cpp` :
   - Include relatif : `#include "../include/ModuleName.hpp"`.
   - Implémentation des méthodes.
   - Fonctions helper `static` en bas du fichier.

3. Ajouter l'include dans `include/libftpp.hpp`.

4. Ajouter le module au `Makefile` (si nécessaire).

5. Créer des tests dans `tests/test_ModuleName.cpp`.

6. Documenter dans `TODO.md` ou la doc du projet.

---

## Exemple de structure de fichier

### Header (`include/StringUtils.hpp`)

```cpp
#pragma once

#include <string>
#include <vector>

namespace libftpp {
namespace str {

class StringUtils {
private:
    StringUtils() {};
    StringUtils(const StringUtils& other) { (void)other; };
    StringUtils& operator=(const StringUtils& other) { 
        (void)other; 
        return *this; 
    };
    ~StringUtils() {};

    static bool is_space(unsigned char c);

public:
    /**
     * @brief Retire les espaces au début et à la fin
     * @param s La chaîne à traiter
     * @return Nouvelle chaîne sans espaces aux extrémités
     */
    static std::string trim(const std::string& s);
    
    static std::string ltrim(const std::string& s);
    static std::string rtrim(const std::string& s);
};

} // namespace str
} // namespace libftpp
```

### Implémentation (`src/StringUtils.cpp`)

```cpp
#include "../include/StringUtils.hpp"
#include <cctype>

using libftpp::str::StringUtils;

// Méthodes publiques en premier

std::string StringUtils::trim(const std::string& s)
{
    return rtrim(ltrim(s));
}

std::string StringUtils::ltrim(const std::string& s)
{
    size_t i = 0;
    while (i < s.size() && is_space((unsigned char)s[i]))
        ++i;
    return s.substr(i);
}

std::string StringUtils::rtrim(const std::string& s)
{
    if (s.empty())
        return s;
    
    size_t i = s.size();
    while (i > 0 && is_space((unsigned char)s[i - 1]))
        --i;
    return s.substr(0, i);
}

// Fonctions helper static en bas

bool StringUtils::is_space(unsigned char c)
{
    return std::isspace(c) != 0;
}
```

---

## 9. Intégration dans les projets

### Utilisation de la bibliothèque

```cpp
#include "libftpp.hpp"

int main() {
    // Utilisation des modules
    std::string s = "  hello  ";
    std::string trimmed = libftpp::str::StringUtils::trim(s);
    
    // Logging
    libftpp::debug::DebugLogger logger("debug.log");
    logger << "Message: " << trimmed << std::endl;
    
    return 0;
}
```

### Compilation avec libftpp

```bash
# Lier la bibliothèque statique
c++ -std=c++98 -Wall -Wextra -Werror main.cpp -I../LIBFTPP/include -L../LIBFTPP -lftpp -o mon_programme

# Ou avec la bibliothèque partagée
c++ -std=c++98 -Wall -Wextra -Werror main.cpp -I../LIBFTPP/include -L../LIBFTPP -lftpp -o mon_programme
```

---

## 10. Conventions spécifiques

### Gestion des erreurs

- **Pas d'exceptions** (C++98 à 42 ne les encourage pas).
- **Retours booléens** : `true` = succès, `false` = échec.
- **Paramètres de sortie** : Passer par référence pour récupérer les résultats.

```cpp
bool parse_int(const std::string& s, int& out);
```

### Constness

- **Méthodes const** : Toute méthode qui ne modifie pas l'état doit être `const`.
- **Paramètres const** : Systématiquement pour les références en lecture seule.

### Types

- **`size_t`** pour les tailles et indices.
- **`std::string::npos`** pour indiquer "non trouvé".
- **Cast explicites** : Préférer les casts C++ (`static_cast`, etc.) sauf si C++98 impose le C-style.

---

## Notes finales

Cette bibliothèque est **utilitaire**, **générique** et **personnelle**. Elle sert de fondation pour tous vos projets C++.

**Philosophie** :
- **Réutilisabilité** : Tout code répétitif dans vos projets CPP est candidat à l'intégration dans libftpp.
- **Qualité** : Code propre, testé, et bien documenté.
- **Compatibilité** : C++98 pour fonctionner partout (projets académiques, systèmes legacy, etc.).
- **Pragmatisme** : Les règles servent la qualité du code, pas l'inverse. Adapter si nécessaire.
