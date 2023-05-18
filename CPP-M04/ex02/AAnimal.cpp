/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:55:55 by leferrei          #+#    #+#             */
/*   Updated: 2023/03/08 16:39:17 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal( void ){
	std::cout << "AAnimal constructed" << std::endl;
}

AAnimal::AAnimal(const AAnimal &a)
{
	std::cout << "AAnimal constructed" << std::endl;
	*this = a;
}

AAnimal &AAnimal::operator= (const AAnimal &a)
{
	std::cout << "AAnimal assigned" << std::endl;
	if (this != &a)
		_type = a._type;
	return (*this);
}

AAnimal::~AAnimal( void ) {
	std::cout << "AAnimal Destructed" << std::endl;
}

const std::string &AAnimal::get_type( void ) const { return (_type); }
