#include "zombie.hpp"
#include "debug.hpp"
#include <sstream>


//constructeur default
Zombie::Zombie(void) {
	std::ostringstream txt;
	txt << this->name << " was created";
	print_debug(txt.str());
}

// destreucteur default
Zombie::~Zombie(void) {
	std::ostringstream txt;

	txt << this->name << " was deleted";
	print_debug(txt.str());
}


// operateur de copie
Zombie::Zombie(const Zombie& other) {
	this->name = other.name;
}

//operateur copie autre ??
Zombie& Zombie::operator=(const Zombie& other){
	this->name = other.name;

	return *this;
}


//setter pour le name
void Zombie::setName(const std::string& str) {
	this->name = str;
}


//getter pour le name
const std::string& Zombie::getName() const {
	return this->name;	
}

//constructeur avec setter pour name
Zombie::Zombie(const std::string& name) {
	this->name = name;
}