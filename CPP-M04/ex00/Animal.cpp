/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:55:55 by leferrei          #+#    #+#             */
/*   Updated: 2023/03/07 16:17:01 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal( void ){}

Animal::Animal(const Animal &a)
{
	*this = a;
}

Animal &Animal::operator= (const Animal &a)
{
	if (this != &a)
		_type = a._type;
	return (*this);
}

Animal::~Animal( void ) {}

const std::string &Animal::get_type( void ) const { return (_type); }

void	Animal::makeSound( void ) const 
{
	if (_type == "Cat")
		std::cout << "Miaaaaawwooo" << std::endl;
	else if (_type == "Dog")
		std::cout << "WOOF WOOF WOOF" << std::endl;
}