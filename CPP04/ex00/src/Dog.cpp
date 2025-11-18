#include "../includes/Dog.hpp"

// Constructeur par défaut
Dog::Dog() {
	this->type = "Dog";
	std::cout << "🐶 Dog: Default constructor called - I'm a good boy!" << std::endl;
}

// Constructeur de copie
Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "🐶 Dog: Copy constructor called - Cloning the good boy!" << std::endl;
}

// Destructeur
Dog::~Dog() {
	std::cout << "🐶 Dog: Destructor called - Goodbye, human friend..." << std::endl;
}

// Opérateur d'affectation
Dog& Dog::operator=(const Dog& other) {
	std::cout << "🐶 Dog: Assignment operator called" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
	}
	return *this;
}

// Fonction makeSound redéfinie
void Dog::makeSound() const {
	std::cout << "🔊 Woof! Woof! Bark bark! 🐕" << std::endl;
}
