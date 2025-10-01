#include "include/zombie.hpp"
#include "include/debug.hpp"
#include <sstream>

Zombie::Zombie(void) {
	std::ostringstream txt;

	txt << this->name << " was created";
	print_debug(txt.str());
}

Zombie::~Zombie(void) {
	std::ostringstream txt;

	txt << this->name << " was deleted";
	print_debug(txt.str());
}

Zombie::Zombie(const Zombie& other) {
	this->name = other.name;
}

Zombie& Zombie::operator=(const Zombie& other){
	this->name = other.name;

	return *this;
}

void Zombie::setName(const std::string& str) {
	this->name = str;
}

const std::string& Zombie::getName() const {
	return this->name;	
}

void announce(void) {

}