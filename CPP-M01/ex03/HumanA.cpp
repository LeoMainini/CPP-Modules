#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &wep): name(name), weapon(wep)
{ 
	//weapon = wep;
	return ;
}

HumanA::~HumanA() { return ;}

void	HumanA::attack( void ) const
{
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}