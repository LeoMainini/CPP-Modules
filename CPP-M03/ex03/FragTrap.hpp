/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:22:18 by leferrei          #+#    #+#             */
/*   Updated: 2023/03/06 14:53:53 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_H
# define FRAG_TRAP_H

#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap(const FragTrap &ct);
		FragTrap(std::string name);
		FragTrap &operator = (const FragTrap &ct);
		~FragTrap();
		void	attack(const std::string& target);
		void	highFivesGuys( void );
};

#endif