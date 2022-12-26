#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name): name(name), weapon(0) {return ;}

HumanB::~HumanB( void ) 
{
	//if (this->weapon != 0)
	//	delete(this->weapon); 
	return ;
}
void	HumanB::setWeapon(Weapon &wep)
{
	//if (this->weapon != 0)
	//	delete this->weapon;
	//this->weapon = new Weapon;
	this->weapon = &wep;
}

void	HumanB::attack( void ) const
{
	this->weapon
		? std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl
		: std::cout << this->name << " has no weapon to attack with" << std::endl;
}