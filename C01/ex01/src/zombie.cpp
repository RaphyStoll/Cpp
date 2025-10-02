#include "zombie.hpp"
#include "debug.hpp"

Zombie::Zombie(void) {
	print_debug("a new Zombie was created");
}

Zombie::~Zombie(void) {
	print_debug("a Zombie was deleted");
}

void Zombie::announce() const {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(const std::string& str) {
	this->name = str;
}