#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal {
	protected:
		std::string type;

	public:
		// Constructeurs et destructeur
		Animal();
		Animal(const Animal& other);
		virtual ~Animal();

		// Opérateur d'affectation
		Animal& operator=(const Animal& other);

		// Fonctions membres
		virtual void makeSound() const = 0;  // Fonction virtuelle PURE → Animal devient abstraite
		std::string getType() const;
};

#endif
