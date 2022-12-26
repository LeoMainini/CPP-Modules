#include "Zombie.hpp"

Zombie*	newZombie(std::string name)
{
	Zombie	*zombose = 0;

	zombose = new Zombie(name);
	return (zombose);
}