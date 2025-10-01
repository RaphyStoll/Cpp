#include "zombie.hpp"
#include <iostream>


//This function creates a zombie, names it, and returns it so you can use it outside
//of the function scope.
Zombie* newZombie(std::string name) {
	return new Zombie(name);
}


//This function creates a zombie, names it, and makes it announce itself.
void randomChump(std::string name) {
	Zombie _new = Zombie(); //constructeur
	_new.setName(name); // renomer -> methode setter
	_new.announce(); // appel methode annonce
}


/*
announce themselves as follows:
<name>: BraiiiiiiinnnzzzZ...
Do not print the angle brackets (< and >). For a zombie named Foo, the message
would be:
Foo: BraiiiiiiinnnzzzZ...
*/
void Zombie::announce(void) {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}