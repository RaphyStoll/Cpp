#include "include/zombie.hpp"

//This function creates a zombie, names it, and returns it so you can use it outside
//of the function scope.
Zombie* newZombie( std::string name ) {
	Zombie _new = Zombie();
	setname(name);

	return &_new;
}


//This function creates a zombie, names it, and makes it announce itself.
void randomChump( std::string name ) {

}
/*
announce themselves as follows:
<name>: BraiiiiiiinnnzzzZ...
Do not print the angle brackets (< and >). For a zombie named Foo, the message
would be:
Foo: BraiiiiiiinnnzzzZ...
*/
void annonce(void) {

}