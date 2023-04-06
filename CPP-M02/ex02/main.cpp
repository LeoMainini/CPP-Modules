/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:05:52 by leferrei          #+#    #+#             */
/*   Updated: 2023/04/06 17:03:44 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

float tf(int num)
{
	int	i;
	int	l_decimal;
	float d_value;

	d_value = 0;
	l_decimal = num;
	while (l_decimal > 1)
		l_decimal = l_decimal >> 1;
	i = 0;
	while (++i && l_decimal != 8)
	{
		if (num & l_decimal)
			d_value += 1 / (2 * i);
		l_decimal = l_decimal << 1;
	}
	return ((float)num + d_value);
}

int main( void )
{
Fixed a;
Fixed b( 10 );
Fixed const c( 42.42f );
Fixed const d( b );

a = Fixed( 1234.4321f );
std::cout << "a is " << a << std::endl;
std::cout << "b is " << b << std::endl;
std::cout << "c is " << c << std::endl;
std::cout << "d is " << d << std::endl;

std::cout << "a < b = " << (a < b) << std::endl;
std::cout << "(a > b) " << (a > b) << std::endl;
std::cout << "(a == b) " << (a == b) << std::endl;
std::cout << "(a != b) " << (a != b) << std::endl;

std::cout << "a - b = " << (a - b) << std::endl;
std::cout << "(a + b) " << (a + b) << std::endl;
std::cout << "(a * b) " << (a * b) << std::endl;
std::cout << "(a / b) " << (a / b) << std::endl;

a = Fixed(0);
b = Fixed( Fixed( 5.05f ) + Fixed( 2 ) );
std::cout << "initial a " << a << std::endl;
std::cout << "value of ++a " << ++a << std::endl;
std::cout << "value of a after ++a " << a << std::endl;
std::cout << "value of a++ " << a++ << std::endl;
std::cout << "value of a after a++ " << a << std::endl;
std::cout << "value of b = 5.05f + 2 " << b << std::endl;

std::cout << Fixed::min( a, b ) << std::endl;
std::cout << Fixed::min( c, d ) << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;
std::cout << Fixed::max( c, d ) << std::endl;


return 0;
}