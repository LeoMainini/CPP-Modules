/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:05:52 by leferrei          #+#    #+#             */
/*   Updated: 2023/02/16 23:11:42 by leferrei         ###   ########.fr       */
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
Fixed const b( 10 );
Fixed const c( 42.42f );
Fixed const d( b );

a = Fixed( 1234.4321f );
std::cout << "a is " << a << std::endl;
std::cout << "b is " << b << std::endl;
std::cout << "c is " << c << std::endl;
std::cout << "d is " << d << std::endl;
std::cout << "a is " << a.toInt() << " as integer" << std::endl;
std::cout << "b is " << b.toInt() << " as integer" << std::endl;
std::cout << "c is " << c.toInt() << " as integer" << std::endl;
std::cout << "d is " << d.toInt() << " as integer" << std::endl;
return 0;
}