#include "Fixed.hpp"

Fixed::Fixed( void ){ this->integral = 0; }

Fixed::~Fixed() { return ; }

Fixed::Fixed( const Fixed &n)
{
	this->integral = n.getRawBits();
}

Fixed	&Fixed::operator= (const Fixed &n)
{
	if (this != &n)
		this->setRawBits(n.getRawBits());
	return (*this);
}

void	Fixed::setRawBits( int const raw)
{
	this->integral = raw;
}

int	Fixed::getRawBits( void ) const
{
	return (this->integral);
}