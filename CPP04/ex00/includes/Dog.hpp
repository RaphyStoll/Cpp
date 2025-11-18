#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
	public:
		// Constructeurs et destructeur
		Dog();
		Dog(const Dog& other);
		~Dog();

		// Opérateur d'affectation
		Dog& operator=(const Dog& other);

		// Fonction membre redéfinie
		void makeSound() const;
};

#endif
