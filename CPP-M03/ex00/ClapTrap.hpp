/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:26:00 by leferrei          #+#    #+#             */
/*   Updated: 2023/03/03 16:28:51 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_H
# define CLAP_TRAP_H
# include <iostream>

class ClapTrap
{

	private:
		std::string name;
		int			health;
		int			energy;
		int			damage;
		
	public:
		ClapTrap();
		ClapTrap(const ClapTrap &ct);
		ClapTrap(std::string name);
		ClapTrap &operator = (const ClapTrap &ct);
		~ClapTrap();
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

};

#endif