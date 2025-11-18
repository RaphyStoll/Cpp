#include "../includes/Cat.hpp"

// Constructeur par défaut
Cat::Cat() {
	this->type = "Cat";
	std::cout << "🐱 Cat: Default constructor called - Meow, I own you now!" << std::endl;
}

// Constructeur de copie
Cat::Cat(const Cat& other) : Animal(other) {
	std::cout << "🐱 Cat: Copy constructor called - Another cat to rule the world!" << std::endl;
}

// Destructeur
Cat::~Cat() {
	std::cout << "🐱 Cat: Destructor called - I leave on my own terms..." << std::endl;
}

// Opérateur d'affectation
Cat& Cat::operator=(const Cat& other) {
	std::cout << "🐱 Cat: Assignment operator called" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
	}
	return *this;
}

// Fonction makeSound redéfinie
void Cat::makeSound() const {
	std::cout << "🔊 Meow! Miaow! Purr purr~ 🐈" << std::endl;
}
