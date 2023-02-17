#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed( void )
{
	std::cout << "Constructor called\n";
}

Fixed::Fixed( const float num ) : integral( num * (1 << this->decimal))
{
	std::cout << "Float constructor called\n";
}

Fixed::Fixed( const int num )
{
	std::cout << "Int constructor called\n";
	this->integral = num << 8;
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
	return (this->integral >> this->decimal);
}


float Fixed::toFloat( void ) const
{
	return ((this->integral / (float)(1 << this->decimal) ));
}