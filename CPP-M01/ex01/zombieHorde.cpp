#include "Zombie.hpp"

Zombie*	zombieHorde(int n, std::string name)
{
	Zombie	*horde = 0;

	horde = new Zombie[n];
	if (n < 1 || horde == 0)
		return (0);
	for (int i = 0; i < n; i++)
	{
		horde[i].name = name;
	//	horde[i].announce();
	}
	return (horde);
}