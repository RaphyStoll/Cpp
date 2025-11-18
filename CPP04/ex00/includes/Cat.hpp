#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
	public:
		// Constructeurs et destructeur
		Cat();
		Cat(const Cat& other);
		~Cat();

		// Opérateur d'affectation
		Cat& operator=(const Cat& other);

		// Fonction membre redéfinie
		void makeSound() const;
};

#endif
