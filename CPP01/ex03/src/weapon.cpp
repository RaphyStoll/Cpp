#include "weapon.hpp"

Weapon::Weapon() {
}

Weapon::~Weapon(void) {
}

Weapon::Weapon(const std::string& type) {
	this->type = type;
}

const std::string& Weapon::getType() const {
	return this->type;
}

void Weapon::setType(const std::string& newType) {
	this->type = newType;
	
}