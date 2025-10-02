#include "zombie.hpp"
#include "config.hpp"

int main ()
{
	int n = 10;
	std::string name = "Fleau";
	Zombie* horde = zombieHorde(n, name);
	if (!horde)
	{
		std::cerr << "Horde allocation error" << std::endl;
		return 1;
	}
	for (int i = 0; i < n; i++)
		horde[i].announce();
	delete[] horde;
	return 0;
}