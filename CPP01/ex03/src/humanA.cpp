#include "humanA.hpp"
#include "debug.hpp"

HumanA::HumanA(const std::string& name, Weapon &weapon) : name(name), weapon(weapon) {
	print_debug("HumanA '" + this->name + "' created");
}

HumanA::~HumanA() {
	print_debug("HumanA '" + this->name + "' destroyed");
}

void HumanA::attack() const {
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}
