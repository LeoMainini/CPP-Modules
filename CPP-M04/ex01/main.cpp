/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:07:59 by leferrei          #+#    #+#             */
/*   Updated: 2023/03/07 16:22:09 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main( void )
{
	Animal	*a = new Animal();
	Animal	*b = new Cat();
	Animal	*c = new Dog();
	Animal	d = *b;

	std::cout << a->get_type() << std::endl;
	std::cout << b->get_type() << std::endl;
	std::cout << c->get_type() << std::endl;
	std::cout << d.get_type() << std::endl;

	a->makeSound();
	b->makeSound();
	c->makeSound();
	d.makeSound();
	
	delete (a);
	delete (b);
	delete (c);
}