#include "../includes/Cat.hpp"

// Constructeur par défaut
Cat::Cat() : Animal() {
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "🐱 Cat: Default constructor called - Meow, I own you now (and I have a brain)!" << std::endl;
}

// Constructeur de copie (DEEP COPY du Brain!)
Cat::Cat(const Cat& other) : Animal(other) {
	std::cout << "🐱 Cat: Copy constructor called - Another cat to rule the world with a cloned brain!" << std::endl;
	this->brain = new Brain(*other.brain);
}

// Destructeur
Cat::~Cat() {
	delete this->brain;
	std::cout << "🐱 Cat: Destructor called - I leave on my own terms..." << std::endl;
}

// Opérateur d'affectation (DEEP COPY du Brain!)
Cat& Cat::operator=(const Cat& other) {
	std::cout << "🐱 Cat: Assignment operator called" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
		delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	return *this;
}

// Fonction makeSound redéfinie
void Cat::makeSound() const {
	std::cout << "🔊 Meow! Miaow! Purr purr~ 🐈" << std::endl;
}

// Getter pour le Brain
Brain* Cat::getBrain() const {
	return this->brain;
}
