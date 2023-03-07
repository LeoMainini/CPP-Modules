/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:45:01 by leferrei          #+#    #+#             */
/*   Updated: 2023/03/07 14:40:18 by leferrei         ###   ########.fr       */
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
	ClapTrap(name.substr(0, name.length()).append("_clap_name")),
	ScavTrap(name.substr(0, name.length()).append("_clap_name")),
	FragTrap(name.substr(0, name.length()).append("_clap_name")),
	name(name)
{
	this->health = FragTrap::health;
	this->damage = FragTrap::damage;
	this->energy = ScavTrap::energy;
}

DiamondTrap::DiamondTrap(const DiamondTrap &st): 
	ClapTrap(st),
	ScavTrap(st),
	FragTrap(st)
{
	this->damage = st.damage;
	this->health = st.health;
	this->energy = st.energy;
	this->name = st.name;
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