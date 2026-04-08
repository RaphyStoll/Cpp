# C++ Module 05 - Exceptions et hiérarchies métier

Ce module travaille les exceptions et leur intégration dans un flux métier structuré autour de règles de validation, de niveaux d'autorité et d'actions autorisées ou non.

## Objectif du module

L'idée est d'apprendre à signaler proprement les erreurs, à propager un état invalide sans casser le programme, et à modéliser des contrôles d'accès lisibles.

## Exercices

### ex00 - Bureaucrat

Première classe du module, centrée sur un grade et ses contraintes. L'exercice impose de contrôler les bornes et de lever les exceptions adaptées quand les règles sont violées.

### ex01 - Form

Ajout d'une classe `Form` liée à un `Bureaucrat`. Le code doit vérifier qu'une signature n'est possible que si le grade requis est respecté.

### ex02 - Shrubbery, robotomy and pardon

Extension du système avec plusieurs formulaires concrets. Chaque formulaire encapsule une action spécifique, tout en héritant d'un contrat commun et d'une logique d'exécution contrôlée.

### ex03 - Intern

Factory simple capable de créer le bon type de formulaire à partir d'une chaîne de caractères. L'exercice conclut le module en introduisant une sélection dynamique d'objets.

## Compilation et exécution

Chaque exercice se compile indépendamment.

```bash
make
./nom_du_programme
```

## Points d'attention

- Exceptions explicites et cohérentes.
- Validation des préconditions avant toute action.
- Messages d'erreur lisibles et stables.
- Hiérarchie métier claire entre classes de base et classes concrètes.
