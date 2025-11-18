#include "../includes/Brain.hpp"

// Constructeur par défaut
Brain::Brain() {
	std::cout << "🧠 Brain: Default constructor called - Creating a new brain with 100 ideas!" << std::endl;
	for (int i = 0; i < 100; i++) {
		ideas[i] = "";
	}
}

// Constructeur de copie (DEEP COPY!)
Brain::Brain(const Brain& other) {
	std::cout << "🧠 Brain: Copy constructor called - Cloning all ideas!" << std::endl;
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = other.ideas[i];
	}
}

// Destructeur
Brain::~Brain() {
	std::cout << "🧠 Brain: Destructor called - Brain is shutting down..." << std::endl;
}

// Opérateur d'affectation (DEEP COPY!)
Brain& Brain::operator=(const Brain& other) {
	std::cout << "🧠 Brain: Assignment operator called - Copying all ideas!" << std::endl;
	if (this != &other) {
		for (int i = 0; i < 100; i++) {
			this->ideas[i] = other.ideas[i];
		}
	}
	return *this;
}

// Setter pour une idée
void Brain::setIdea(int index, const std::string& idea) {
	if (index >= 0 && index < 100) {
		this->ideas[index] = idea;
	}
}

// Getter pour une idée
std::string Brain::getIdea(int index) const {
	if (index >= 0 && index < 100) {
		return this->ideas[index];
	}
	return "";
}
