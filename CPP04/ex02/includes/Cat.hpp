#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
	private:
		Brain* brain;

	public:
		// Constructeurs et destructeur
		Cat();
		Cat(const Cat& other);
		~Cat();

		// Opérateur d'affectation
		Cat& operator=(const Cat& other);

		// Fonction membre redéfinie
		void makeSound() const;
		
		// Fonctions pour accéder au Brain
		Brain* getBrain() const;
};

#endif
