#pragma once
#include <iostream>

class Zombie {
	private:
		std::string	name;
		int			index;
	public:
		Zombie();
		~Zombie();
		void announce() const;
		void setName(const std::string& name);
};
Zombie* zombieHorde( int N, std::string name );