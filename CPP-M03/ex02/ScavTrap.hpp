/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:00:59 by leferrei          #+#    #+#             */
/*   Updated: 2023/03/06 14:16:17 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_H
# define SCAV_TRAP_H

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(const ScavTrap &ct);
		ScavTrap(std::string name);
		ScavTrap &operator = (const ScavTrap &ct);
		~ScavTrap();
		void	attack(const std::string& target);
		void	guardGate();
};

#endif