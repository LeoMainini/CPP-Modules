/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:03:41 by leferrei          #+#    #+#             */
/*   Updated: 2023/03/06 16:10:13 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->health = 100;
	this->energy = 50;
	this->damage = 20;
	std::cout << "ScavTrap " << name << " constructed!" << std::endl;
}

ScavTrap::ScavTrap(): ClapTrap() {
	this->health = 100;
	this->energy = 50;
	this->damage = 20;
	std::cout << "default nameless ScavTrap constructed!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &st): ClapTrap(st){
	this->damage = st.damage;
	this->health = st.health;
	this->energy = st.energy;
	this->name = st.name;
	std::cout << "ScavTrap copy constructor called! " << st.name << " has been duplicated!" << std::endl;
}

ScavTrap &ScavTrap::operator = (const ScavTrap &ct)
{
	std::cout << "ScavTrap assignement constructor called! " << ct.name << " has been duplicated!" << std::endl;
	if (this == &ct)
		return (*this);
	this->name = ct.name;
	this->health = ct.health;
	this->energy = ct.energy;
	this->damage = ct.damage;
	return (*this);
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->name << " destroyed!" << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (!this->energy || !this->health)
	{
		std::cout << "ScavTrap " << this->name << " has no energy or health left, he cant attack!" << std::endl;
		return ;
	}
	this->energy --;
	std::cout << "ScavTrap " <<  this->name << " attacks " << target << ", causing " << this->damage
		<< " points of damage! Energy left " << this->energy << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode" << std::endl;
}