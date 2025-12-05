#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

#include <iostream>

// int main()
// {
// 	IMateriaSource* src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());

// 	ICharacter* me = new Character("me");

// 	AMateria* tmp;
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);

// 	ICharacter* bob = new Character("bob");

// 	std::cout << "\n--- Original Test Case Output ---" << std::endl;
// 	me->use(0, *bob);
// 	me->use(1, *bob);

// 	std::cout << "\n--- Additional Tests ---" << std::endl;

// 	std::cout << "\nTesting Character copy constructor:" << std::endl;
// 	Character* me_copy = new Character(*static_cast<Character*>(me));
// 	std::cout << "me_copy name: " << me_copy->getName() << std::endl;
// 	me_copy->use(0, *bob);
// 	me_copy->use(1, *bob);

// 	std::cout << "\nTesting Character assignment operator:" << std::endl;
// 	Character* another_char = new Character("another");
// 	AMateria* fire = new Ice();
// 	another_char->equip(fire);
// 	std::cout << "another_char before assignment:" << std::endl;
// 	another_char->use(0, *bob);

// 	*another_char = *static_cast<Character*>(me);
// 	std::cout << "another_char after assignment from me:" << std::endl;
// 	another_char->use(0, *bob);
// 	another_char->use(1, *bob);

// 	std::cout << "\n--- Unequip Test ---" << std::endl;
// 	me->unequip(0);
// 	me->use(0, *bob);
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	me->use(0, *bob);

// 	std::cout << "\n--- MateriaSource Copy Test ---" << std::endl;
// 	MateriaSource* src_copy = new MateriaSource(*static_cast<MateriaSource*>(src));
// 	AMateria* new_ice = src_copy->createMateria("ice");
// 	if (new_ice)
// 	{
// 		std::cout << "src_copy created " << new_ice->getType() << std::endl;
// 		delete new_ice;
// 	}
// 	else
// 		std::cout << "src_copy failed to create ice" << std::endl;

// 	MateriaSource* another_src = new MateriaSource();
// 	another_src->learnMateria(new Cure());
// 	*another_src = *static_cast<MateriaSource*>(src);
// 	AMateria* new_cure = another_src->createMateria("cure");
// 	if (new_cure)
// 	{
// 		std::cout << "another_src created " << new_cure->getType() << std::endl;
// 		delete new_cure;
// 	}
// 	else
// 		std::cout << "another_src failed to create cure" << std::endl;

// 	std::cout << "\n--- Cleaning up ---" << std::endl;
// 	delete bob;
// 	delete me;
// 	delete me_copy;
// 	delete another_char;
// 	delete src_copy;
// 	delete another_src;
// 	delete src;
// 	return 0;
// }


int main()
{
IMateriaSource* src = new MateriaSource();
src->learnMateria(new Ice());
src->learnMateria(new Cure());
ICharacter* me = new Character("me");
AMateria* tmp;
tmp = src->createMateria("ice");
me->equip(tmp);
tmp = src->createMateria("cure");
me->equip(tmp);
ICharacter* bob = new Character("bob");
me->use(0, *bob);
me->use(1, *bob);
delete bob;
delete me;
delete src;
return 0;
}