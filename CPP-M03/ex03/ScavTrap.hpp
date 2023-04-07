/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:00:59 by leferrei          #+#    #+#             */
/*   Updated: 2023/04/07 19:31:21 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_H
# define SCAV_TRAP_H

#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(const ScavTrap &ct);
		ScavTrap(std::string name);
		~ScavTrap();
		int			getEnergy( void );
		ScavTrap	&operator = (const ScavTrap &ct);
		void		attack(const std::string& target);
		void		guardGate();
};

#endif