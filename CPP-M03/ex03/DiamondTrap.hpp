/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:38:22 by leferrei          #+#    #+#             */
/*   Updated: 2023/03/06 16:14:27 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMOND_TRAP_H
# define DIAMOND_TRAP_H

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap 
{
	private:
		std::string	name;
	
	public:
		DiamondTrap();
		DiamondTrap(const DiamondTrap &ct);
		DiamondTrap(std::string name);
		DiamondTrap &operator = (const DiamondTrap &ct);
		~DiamondTrap();
		void	attack(std::string target);
		void whoAmI( void );
};

#endif