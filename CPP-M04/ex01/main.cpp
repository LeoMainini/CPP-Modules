/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:07:59 by leferrei          #+#    #+#             */
/*   Updated: 2023/03/08 15:39:48 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main( void )
{
	std::cout << "CONSTRUCTIONS\n\n";
	Animal	*a = new Animal();
	Animal	*b = new Cat();
	Animal	*c = new Dog();
	Animal	&d = *b;
	Dog		*dog = new Dog();
	Dog		dog2(*dog);

	std::cout << "\nTYPES\n\n";
	std::cout << "a " << a->get_type() << std::endl;
	std::cout << "b " << b->get_type() << std::endl;
	std::cout << "c " << c->get_type() << std::endl;
	std::cout << "d " << d.get_type() << std::endl;
	std::cout << "dog " << dog->get_type() << std::endl;
	std::cout << "dog2 " << dog2.get_type() << std::endl;

	std::cout << "\nSOUNDS (a, b, c, d, dog, dog2)\n\n";
	a->makeSound();
	b->makeSound();
	c->makeSound();
	d.makeSound();
	dog->makeSound();
	dog2.makeSound();

	std::cout << "\nDESTRUCTIONS\n\n";
	delete (a);
	delete (b);
	delete (c);
	delete (dog);
}