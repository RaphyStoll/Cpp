#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
	private:
		Brain* brain;

	public:
		// Constructeurs et destructeur
		Dog();
		Dog(const Dog& other);
		~Dog();

		// Opérateur d'affectation
		Dog& operator=(const Dog& other);

		// Fonction membre redéfinie
		void makeSound() const;
		
		// Fonctions pour accéder au Brain
		Brain* getBrain() const;
};

#endif
