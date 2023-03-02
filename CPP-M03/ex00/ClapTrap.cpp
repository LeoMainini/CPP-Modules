#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name): name(name) {
	std::cout << "ClapTrap " << name << " constructed!" << std::endl;
}

ClapTrap::~ClapTrap() {
		std::cout << "ClapTrap " << this->name << " destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (!this->energy || this->health)
	{
		std::cout << this->name << " has no energy or health left, he cant attack!" << std::endl;
		return ;
	}
	std::cout << this->name << "attacks " << target << ", causing " << this->damage
		<< " points of damage!" << std::endl;
	this->energy --;
	
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->health == 0)
		std::cout << this->name << " cant take any more damage, its already dead!" << std::endl;
	else if (this->health - amount < 0)
		std::cout << this->name << " takes " << amount << "damage and dies! Health = 0" << std::endl;
	else
	{
		this->health -= amount;
		std::cout << this->name << " takes " << amount << "damage! Health = " << this->health << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->energy || !this->health)
	{
		std::cout << this->name << " has no energy or health left, he cant be repaired!" << std::endl;
		return ;
	}
	this->health += amount;
	this->energy --:
}