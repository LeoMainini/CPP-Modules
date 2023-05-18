/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:55:55 by leferrei          #+#    #+#             */
/*   Updated: 2023/03/07 16:17:01 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal( void ){}

AAnimal::AAnimal(const AAnimal &a)
{
	*this = a;
}

AAnimal &AAnimal::operator= (const AAnimal &a)
{
	if (this != &a)
		_type = a._type;
	return (*this);
}

AAnimal::~AAnimal( void ) {}

const std::string &AAnimal::get_type( void ) const { return (_type); }

void	AAnimal::makeSound( void ) const 
{
	if (_type == "Cat")
		std::cout << "Miaaaaawwooo" << std::endl;
	else if (_type == "Dog")
		std::cout << "WOOF WOOF WOOF" << std::endl;
}