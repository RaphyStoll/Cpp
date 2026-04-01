import os

def write_file(path, content):
    with open(path, "w") as f:
        f.write(content)

write_file("CPP08/ex00/Makefile", """NAME = easyfind
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
\t$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
\trm -f $(OBJ)

fclean: clean
\trm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
""")

write_file("CPP08/ex01/Span.hpp", """#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>

class Span {
private:
    unsigned int _maxSize;
    std::vector<int> _numbers;
    
    Span(); 

public:
    Span(unsigned int n);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int number);
    
    template <typename Iterator>
    void addNumber(Iterator begin, Iterator end) {
        if (std::distance(begin, end) + _numbers.size() > _maxSize) {
            throw SpanFullException();
        }
        _numbers.insert(_numbers.end(), begin, end);
    }

    int shortestSpan() const;
    int longestSpan() const;

    class SpanFullException : public std::exception {
        virtual const char* what() const throw();
    };

    class NoSpanFoundException : public std::exception {
        virtual const char* what() const throw();
    };
};

#endif
""")

write_file("CPP08/ex01/Span.cpp", """#include "Span.hpp"
#include <numeric>

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int n) : _maxSize(n) {}

Span::Span(const Span& other) : _maxSize(other._maxSize), _numbers(other._numbers) {}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
    if (_numbers.size() >= _maxSize) {
        throw SpanFullException();
    }
    _numbers.push_back(number);
}

int Span::shortestSpan() const {
    if (_numbers.size() <= 1) {
        throw NoSpanFoundException();
    }
    
    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());
    
    int minSpan = sorted[1] - sorted[0];
    for (size_t i = 1; i < sorted.size() - 1; ++i) {
        int diff = sorted[i+1] - sorted[i];
        if (diff < minSpan) {
            minSpan = diff;
        }
    }
    
    return minSpan;
}

int Span::longestSpan() const {
    if (_numbers.size() <= 1) {
        throw NoSpanFoundException();
    }
    
    std::vector<int>::const_iterator minElem = std::min_element(_numbers.begin(), _numbers.end());
    std::vector<int>::const_iterator maxElem = std::max_element(_numbers.begin(), _numbers.end());
    
    return *maxElem - *minElem;
}

const char* Span::SpanFullException::what() const throw() {
    return "Span is already full. Cannot add more elements.";
}

const char* Span::NoSpanFoundException::what() const throw() {
    return "Not enough elements to find a span.";
}
""")

write_file("CPP08/ex01/main.cpp", """#include <iostream>
#include "Span.hpp"
#include <vector>

int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    
    Span sp2(10000);
    std::vector<int> lotsOfNumbers;
    for (int i = 0; i < 10000; ++i) {
        lotsOfNumbers.push_back(i * 2);
    }
    sp2.addNumber(lotsOfNumbers.begin(), lotsOfNumbers.end());
    std::cout << "\\nLarge Span (10000 elements):" << std::endl;
    std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp2.longestSpan() << std::endl;

    return 0;
}
""")

write_file("CPP08/ex01/Makefile", """NAME = span
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Span.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
\t$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
\trm -f $(OBJ)

fclean: clean
\trm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
""")

write_file("CPP08/ex02/MutantStack.hpp", """#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
public:
    MutantStack() : std::stack<T, Container>() {}
    MutantStack(const MutantStack& other) : std::stack<T, Container>(other) {}
    MutantStack& operator=(const MutantStack& other) {
        if (this != &other) {
            std::stack<T, Container>::operator=(other);
        }
        return *this;
    }
    virtual ~MutantStack() {}

    typedef typename Container::iterator iterator;
    typedef typename Container::const_iterator const_iterator;

    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
    
    const_iterator begin() const { return this->c.begin(); }
    const_iterator end() const { return this->c.end(); }
};

#endif
""")

write_file("CPP08/ex02/main.cpp", """#include <iostream>
#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    
    return 0;
}
""")

write_file("CPP08/ex02/Makefile", """NAME = mutantstack
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
\t$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
\trm -f $(OBJ)

fclean: clean
\trm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
""")

write_file("CPP08/README.md", """# C++ Module 08 - Templated Containers, Iterators, Algorithms

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
""")
