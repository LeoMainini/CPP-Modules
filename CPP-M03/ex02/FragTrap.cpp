/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:22:20 by leferrei          #+#    #+#             */
/*   Updated: 2023/03/06 14:27:19 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	this->health = 100;
	this->energy = 100;
	this->damage = 30;
	std::cout << "FragTrap " << name << " constructed!" << std::endl;
}

FragTrap::FragTrap(): ClapTrap() {
	this->health = 100;
	this->energy = 100;
	this->damage = 30;
	std::cout << "default nameless FragTrap constructed!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &st): ClapTrap(st){
	std::cout << "FragTrap copy constructor called! " << st.name << " has been duplicated!" << std::endl;
}

FragTrap &FragTrap::operator = (const FragTrap &ct)
{
	std::cout << "FragTrap assignement constructor called! " << ct.name << " has been duplicated!" << std::endl;
	if (this == &ct)
		return (*this);
	this->name = ct.name;
	this->health = ct.health;
	this->energy = ct.energy;
	this->damage = ct.damage;
	return (*this);
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << this->name << " destroyed!" << std::endl;
}

void	FragTrap::attack(const std::string &target)
{
	if (!this->energy || !this->health)
	{
		std::cout << "FragTrap " << this->name << " has no energy or health left, he cant attack!" << std::endl;
		return ;
	}
	this->energy --;
	std::cout << "FragTrap " <<  this->name << " attacks " << target << ", causing " << this->damage
		<< " points of damage! Energy left " << this->energy << std::endl;
}

void	FragTrap::highFivesGuys( void )
{
	std::cout << "FragTrap " << this->name << " is positively asking for high fives!" << std::endl;
}