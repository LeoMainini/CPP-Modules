/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:17:29 by leferrei          #+#    #+#             */
/*   Updated: 2023/03/07 17:54:42 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ): Animal(), bb(new (std::nothrow) Brain()){
	std::cout << "Dog in construction..... ";
	if (bb)
	{
		std::cout << " Done" << std::endl;
		_type = "Dog";
	}
	else
	{
		std::cout << "Failed" << std::endl;
		_type = "NULL";
	}
}
Dog::Dog( const Dog &a) {
	std::cout << "Dog constructed" << std::endl;
	*this = a;
}
Dog &Dog::operator = (const Dog &a) {
	std::cout << "Dog assigned" << std::endl;
	if (this != &a)
	{
		if (_type.length() > 0 && _type.compare("NULL"))
			delete (bb);
		bb = new (std::nothrow) Brain();
		if (bb)
			bb = a.bb;
		else
			std::cout << "Brain copy alloDogion failed" << std::endl;
		Animal::_type = a.get_type();
	}
	return (*this);
}
Dog::~Dog( void ) {
	delete bb;
	std::cout << "Dog destructed" << std::endl;
}