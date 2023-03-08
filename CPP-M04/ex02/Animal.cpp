/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:55:55 by leferrei          #+#    #+#             */
/*   Updated: 2023/03/08 16:39:17 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal( void ){
	std::cout << "Animal constructed" << std::endl;
}

Animal::Animal(const Animal &a)
{
	std::cout << "Animal constructed" << std::endl;
	*this = a;
}

Animal &Animal::operator= (const Animal &a)
{
	std::cout << "Animal assigned" << std::endl;
	if (this != &a)
		_type = a._type;
	return (*this);
}

Animal::~Animal( void ) {
	std::cout << "Animal Destructed" << std::endl;
}

const std::string &Animal::get_type( void ) const { return (_type); }
