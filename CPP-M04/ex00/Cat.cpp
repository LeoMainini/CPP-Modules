/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:31:21 by leferrei          #+#    #+#             */
/*   Updated: 2023/03/07 16:17:15 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ): Animal(){
	this->_type = "Cat";
}
Cat::Cat( const Cat &a) { 
	*this = a;
}
Cat &Cat::operator = (const Cat &a) {
	if (this != &a)
		Animal::_type = a.get_type();
	return (*this);
}
Cat::~Cat( void ) { }