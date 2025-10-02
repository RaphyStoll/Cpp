#include "weapon.hpp"
#include "humanA.hpp"
#include "humanB.hpp"
#include <iostream>

int main() {
	Weapon club = Weapon("crude spiked club");
	HumanA bob("Bob", club);
	bob.attack();

	HumanB jim("Jim");
	jim.attack();
	jim.setWeapon(club);
	jim.attack();

	club.setType("some other type of club");
	bob.attack();
	jim.attack();

	return 0;
}