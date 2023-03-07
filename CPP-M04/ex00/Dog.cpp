/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:17:29 by leferrei          #+#    #+#             */
/*   Updated: 2023/03/07 16:18:08 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ): Animal(){
	_type = "Dog";
}
Dog::Dog( const Dog &a) { 
	*this = a;
}
Dog &Dog::operator = (const Dog &a) {
	if (this != &a)
		_type = a.get_type();
	return (*this);
}
Dog::~Dog( void ) { }