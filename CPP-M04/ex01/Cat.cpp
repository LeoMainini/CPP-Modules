/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:31:21 by leferrei          #+#    #+#             */
/*   Updated: 2023/03/07 17:53:22 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ): Animal(), bb(new (std::nothrow) Brain()){
	std::cout << "Cat in construction..... ";
	if (bb)
	{
		std::cout << " Done" << std::endl;
		_type = "Cat";
	}
	else
	{
		std::cout << "Failed" << std::endl;
		_type = "NULL";
	}
}
Cat::Cat( const Cat &a) {
	std::cout << "Cat constructed" << std::endl;
	*this = a;
}
Cat &Cat::operator = (const Cat &a) {
	std::cout << "Cat assigned" << std::endl;
	if (this != &a)
	{
		if (_type.length() > 0 && _type.compare("NULL"))
			delete (bb);
		bb = new (std::nothrow) Brain();
		if (bb)
			bb = a.bb;
		else
			std::cout << "Brain copy allocation failed" << std::endl;
		Animal::_type = a.get_type();
	}
	return (*this);
}
Cat::~Cat( void ) {
	delete bb;
	std::cout << "Cat destructed" << std::endl;
}