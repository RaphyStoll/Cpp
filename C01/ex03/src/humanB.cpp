#include "humanB.hpp"
#include "debug.hpp"

HumanB::HumanB(const std::string& name) : name(name), weapon(NULL) {
	print_debug("HumanB '" + this->name + "' created (unarmed)");
}

HumanB::~HumanB() {
	print_debug("HumanB '" + this->name + "' destroyed");
}

void HumanB::setWeapon(Weapon &weapon) {
	this->weapon = &weapon;
	print_debug("HumanB '" + this->name + "' picked up a weapon: " + this->weapon->getType());
}

void HumanB::attack() const {
	if (this->weapon)
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
	else
		std::cout << this->name << " has no weapon" << std::endl;
}
