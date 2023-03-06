/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:03:49 by leferrei          #+#    #+#             */
/*   Updated: 2023/03/03 17:35:56 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name): name(name), health(10), energy(10), damage(0) {
	std::cout << "ClapTrap " << name << " constructed!" << std::endl;
}

ClapTrap::ClapTrap(): name("default"), health(10), energy(10), damage(0) {
	std::cout << "default nameless claptrap constructed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &ct): name(ct.name), health(ct.health),
	energy(ct.energy), damage(ct.damage) {
	std::cout << "ClapTrap copy constructor called! " << ct.name << " has been duplicated!" << std::endl;
}

ClapTrap &ClapTrap::operator = (const ClapTrap &ct)
{
	std::cout << "ClapTrap assignement constructor called! " << ct.name << " has been duplicated!" << std::endl;
	if (this == &ct)
		return (*this);
	this->name = ct.name;
	this->health = ct.health;
	this->energy = ct.energy;
	this->damage = ct.damage;
	return (*this);
}

ClapTrap::~ClapTrap() {
		std::cout << "ClapTrap " << this->name << " destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (!this->energy || !this->health)
	{
		std::cout << this->name << " has no energy or health left, he cant attack!" << std::endl;
		return ;
	}
	this->energy --;
	std::cout << this->name << " attacks " << target << ", causing " << this->damage
		<< " points of damage! Energy left " << this->energy << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->health == 0)
		std::cout << this->name << " cant take any more damage, its already dead!" << std::endl;
	else if (this->health - amount < 0)
		std::cout << this->name << " takes " << amount << " damage and dies! Health = 0" << std::endl;
	else
	{
		this->health -= amount;
		std::cout << this->name << " takes " << amount << " damage! Health = " << this->health << std::endl;
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
	this->energy --;
	std::cout << "Health repaired to " << this->health << ", energy left " << this->energy << std::endl;
}