/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:29:07 by leferrei          #+#    #+#             */
/*   Updated: 2023/03/08 15:37:17 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain( void ) 
{
	std::cout << "Brain constructed";
}

Brain::Brain( const Brain &b)
{
	std::cout << "Brain copied" << std::endl;
	*this = b;
}

Brain &Brain::operator= ( const Brain &b)
{
	int	i = -1;
	std::cout << "Brain copy assigned" << std::endl;
	if (this != &b)
		while(++i < 100)
			ideas[i].assign(b.ideas[i]);
	return (*this);
}

Brain::~Brain() {
	std::cout << "Brain destructed" << std::endl;
}