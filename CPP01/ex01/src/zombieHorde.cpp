#include <iostream>
#include <sstream>
#include "zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	if (N < 1)
		return NULL;
	int index = 0;
	std::ostringstream build_name;
	Zombie* horde = new (std::nothrow) Zombie[N];
	if (!horde)
		return NULL;

	for (int i = 0; i < N; i++)
	{
		index = i + 1;
		build_name.str("");
		build_name.clear();
		build_name << name << " (" << index << ")";
		horde[i].setName(build_name.str());
	}
	return horde;
}