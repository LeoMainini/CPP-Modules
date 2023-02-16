#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed( void )
{
	std::cout << "Constructor called\n";
}

Fixed::Fixed( const float num )
{
	int i = 1;
	float value = num;

	std::cout << "Float constructor called\n";
	while (this->decimal / i > 1)
	{
		value *= 10;
		i *= 2;
	}
	this->integral = roundf(value);
}

Fixed::Fixed( const int num )
{
	int i = 1;
	int	value = num;

	std::cout << "Int constructor called\n";
	while (this->decimal / i > 1)
	{
		value *= 10;
		i *= 2;
	}
	this->integral = value;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed::Fixed( const Fixed &n) : integral(n.getRawBits())
{
	std::cout << "Copy constructor called\n";
}

Fixed	&Fixed::operator= (const Fixed &n)
{
	std::cout << "Assignment constructor called\n";
	if (this != &n)
		this->setRawBits(n.getRawBits());
	return (*this);
}

std::ostream	&operator << (std::ostream &out, const Fixed &n)
{
	out << n.toFloat();
	return (out);
}

void	Fixed::setRawBits( int const raw)
{
	this->integral = raw;
}

int	Fixed::getRawBits( void ) const
{
	return (this->integral);
}

int	Fixed::toInt( void ) const
{
	int	i = 1;
	int	l_int = getRawBits();

	while (this->decimal / i > 1)
	{
		i *= 2;
		l_int /= 10;
	}
	return (l_int);
}


float Fixed::toFloat( void ) const
{
	int		i = 1;
	int		l_int = getRawBits();
	double	result = 0;

	while (this->decimal / i > 1)
	{
		result += l_int % 10;
		l_int /= 10;
		result /= 10;
		i *= 2;
	}
	return (toInt() + result);
}