#include "Zombie.hpp"
#include <string>
#include <iostream>

int	Zombie::_horde_size = 0;

int		Zombie::getHordeSize( void ) const { return _horde_size; }

void	Zombie::incHordeSize( void ) { _horde_size++; }

Zombie::Zombie(std::string name): name(name) { 
	this->index = getHordeSize();
	incHordeSize();	
	return ;
}
void	Zombie::initName(std::string name)
{
	this->name = name;
}

Zombie::~Zombie( void )
{
	std::cout << this->index << ": ";
	std::cout << "Aaaaggghhhh: " << this->name << " died" << std::endl;
}

Zombie::Zombie( void ): name("defaulto papito") { 

	this->index = getHordeSize();
	incHordeSize();	
	return ;
}

void	Zombie::announce( void ) const
{
	std::cout << this->index << ": ";
	std::cout << this->name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}
