/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:45:01 by leferrei          #+#    #+#             */
/*   Updated: 2023/04/07 19:44:52 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap():
	ClapTrap("default_clap_name"),
	ScavTrap("default_clap_name"),
	FragTrap("default_clap_name"),
	name("default_clap_name")
{
	std::cout << "default nameless DiamondTrap created" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name):
	ClapTrap(name.append("_clap_name")),
	ScavTrap(name),
	FragTrap(name),
	name(name.substr(0, name.length() - 10 ))
{
	ScavTrap tmp("temp");
	
	this->health = FragTrap::health;
	this->energy = tmp.getEnergy();
	this->damage = FragTrap::damage;
	std::cout << "DiamondTrap " << this->name << " constructed" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &st): 
	ClapTrap(st),
	ScavTrap(st),
	FragTrap(st)
{
	*this = st;
	std::cout << "DiamondTrap copy constructor called! " << st.name << " has been duplicated!" << std::endl;
}

DiamondTrap &DiamondTrap::operator = (const DiamondTrap &ct)
{
	std::cout << "DiamondTrap copy assignement called! " << ct.name << " has been duplicated!" << std::endl;
	if (this == &ct)
		return (*this);
	this->name = ct.name;
	this->health = ct.health;
	this->energy = ct.energy;
	this->damage = ct.damage;
	return (*this);
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << this->name << " destroyed!" << std::endl;
}

void	DiamondTrap::attack(std::string target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI( void )
{
	std::cout << "I am DiamondTrap " << this->name << 
		" grandson of " << ClapTrap::name << std::endl;
}