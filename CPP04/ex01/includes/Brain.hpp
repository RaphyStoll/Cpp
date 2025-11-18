#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain {
	private:
		std::string ideas[100];

	public:
		// Constructeurs et destructeur
		Brain();
		Brain(const Brain& other);
		~Brain();

		// Opérateur d'affectation
		Brain& operator=(const Brain& other);

		// Getters et setters
		void setIdea(int index, const std::string& idea);
		std::string getIdea(int index) const;
};

#endif
