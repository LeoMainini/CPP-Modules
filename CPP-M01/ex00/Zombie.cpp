#include "Zombie.hpp"
#include <string>
#include <iostream>

Zombie::Zombie(std::string name): name(name) 
{
	return ;
}

Zombie::~Zombie( void )
{
	std::cout << "Aaaaggghhhh: " << this->name << " died" << std::endl;
}

void	Zombie::announce( void )
{
	std::cout << this->name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}