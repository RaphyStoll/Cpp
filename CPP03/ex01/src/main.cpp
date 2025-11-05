#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main() {
	std::cout << "=== ScavTrap quick test ===" << std::endl;

	ScavTrap s("Guardian");
	s.guardGate();
	s.attack("intruder");
	s.takeDamage(90);
	s.attack("intruder2");
	s.beRepaired(50);

	std::cout << "\nTesting copy and assignment" << std::endl;
	ScavTrap s2(s);
	ScavTrap s3("Temp");
	s3 = s;
	s2.attack("copy_target");
	s3.guardGate();

	std::cout << "\nEnd of tests" << std::endl;
	return 0;
}
