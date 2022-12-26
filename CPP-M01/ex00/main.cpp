#include "Zombie.hpp"

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

int	main( void )
{
	Zombie	*zomboni = 0;

	randomChump("Alfredo");
	zomboni = newZombie("Guiseppi Carbonara");
	zomboni->announce();
	delete (zomboni);
}