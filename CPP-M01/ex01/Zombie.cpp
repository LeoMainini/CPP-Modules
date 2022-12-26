#include "Zombie.hpp"
#include <string>
#include <iostream>

int	Zombie::_horde_size = 0;

Zombie::Zombie(std::string name): name(name), index(_horde_size++) { return ; }

Zombie::~Zombie( void )
{
	std::cout << "Aaaaggghhhh: " << this->name <<" number " << this->index << " died" << std::endl;
}

Zombie::Zombie( void ): name("defaulto papito"), index(_horde_size++) { return ; }

void	Zombie::announce( void ) const
{
	std::cout << this->index << ": ";
	std::cout << this->name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}

int	Zombie::getHordeSize( void ) const { return _horde_size; }