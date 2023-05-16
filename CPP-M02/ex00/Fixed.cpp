#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed( void )
{
	this->integral = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed::Fixed( const Fixed &n)
{
	*this = n;
}

Fixed	&Fixed::operator= (const Fixed &n)
{
	std::cout << "Assignement operator called" << std::endl;
	if (this != &n)
		this->setRawBits(n.getRawBits());
	return (*this);
}

void	Fixed::setRawBits( int const raw)
{
	std::cout << "Set raw bits called" << std::endl;
	this->integral = raw;
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "Get raw bits called" << std::endl;
	return (this->integral);
}