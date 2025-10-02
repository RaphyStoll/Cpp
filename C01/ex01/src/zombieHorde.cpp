#include <iostream>
#include "zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	if (N < 1)
		return NULL;
	Zombie* horde = new (std::nothrow) Zombie[N];
	if (!horde)
		return NULL;

	for (int i = 0; i < N; i++)
		horde[i].setName(name);
	return horde;
}