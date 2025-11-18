#include "../includes/Animal.hpp"

// Constructeur par défaut
Animal::Animal() : type("Generic Animal") {
	std::cout << "🐾 Animal: Default constructor called" << std::endl;
}

// Constructeur de copie
Animal::Animal(const Animal& other) : type(other.type) {
	std::cout << "🐾 Animal: Copy constructor called" << std::endl;
}

// Destructeur virtuel (IMPORTANT!)
Animal::~Animal() {
	std::cout << "🐾 Animal: Destructor called" << std::endl;
}

// Opérateur d'affectation
Animal& Animal::operator=(const Animal& other) {
	std::cout << "🐾 Animal: Assignment operator called" << std::endl;
	if (this != &other) {
		this->type = other.type;
	}
	return *this;
}

// Fonction makeSound
void Animal::makeSound() const {
	std::cout << "🔊 *Generic animal sound*" << std::endl;
}

// Getter pour le type
std::string Animal::getType() const {
	return this->type;
}
