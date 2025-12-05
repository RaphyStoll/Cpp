#include "../includes/Dog.hpp"

// Constructeur par défaut
Dog::Dog() : Animal() {
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "🐶 Dog: Default constructor called - I'm a good boy with a brain!" << std::endl;
}

// Constructeur de copie (DEEP COPY du Brain!)
Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "🐶 Dog: Copy constructor called - Cloning the good boy and his brain!" << std::endl;
	this->brain = new Brain(*other.brain);
}

// Destructeur
Dog::~Dog() {
	delete this->brain;
	std::cout << "🐶 Dog: Destructor called - Goodbye, human friend..." << std::endl;
}

// Opérateur d'affectation (DEEP COPY du Brain!)
Dog& Dog::operator=(const Dog& other) {
	std::cout << "🐶 Dog: Assignment operator called" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
		delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	return *this;
}

// Fonction makeSound redéfinie
void Dog::makeSound() const {
	std::cout << "🔊 Woof! Woof! Bark bark! 🐕" << std::endl;
}

// Getter pour le Brain
Brain* Dog::getBrain() const {
	return this->brain;
}
