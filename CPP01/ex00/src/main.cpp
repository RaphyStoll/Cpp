#include "zombie.hpp"
#include <iostream>

int main () {

	//Zombie stack
	Zombie z1;
	z1.setName("Pape François");
	z1.announce();

	//Zombie heap
	Zombie *z2;
	z2 = newZombie("Raph");
	z2->announce();

	randomChump("Jean-Paul 2");

	delete z2;

	return 0;
}