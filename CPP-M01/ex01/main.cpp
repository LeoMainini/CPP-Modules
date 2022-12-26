#include "Zombie.hpp"
#include <iostream>

Zombie*	zombieHorde(int n, std::string name);

int	main( void )
{
	Zombie	*zombussy = 0;

	zombussy = zombieHorde(12, "Guiseppi the sloppy");
	zombussy->announce();
	for(int	i = 1; i < 12; i++)
		zombussy[i].announce();
	delete [] zombussy;
}