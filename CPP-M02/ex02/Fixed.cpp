#include "Fixed.hpp"
#include <cmath>
#include <iostream>

//Constructors and destructors
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

//Value compute functions
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

//Operator overloads
//Assignement
Fixed	&Fixed::operator= (const Fixed &n)
{
	std::cout << "Assignment constructor called\n";
	if (this != &n)
		this->setRawBits(n.getRawBits());
	return (*this);
}

//Comparison
bool Fixed::operator< (const Fixed &n)
{
	static bool result;

	result = this->getRawBits() < n.getRawBits();
	return (result);
}

bool Fixed::operator> (const Fixed &n)
{
	static bool result;

	result = this->getRawBits() > n.getRawBits();
	return (result);
}

bool Fixed::operator<= (const Fixed &n)
{
	static bool result;

	result = this->getRawBits() <= n.getRawBits();
	return (result);
}

bool Fixed::operator== (const Fixed &n)
{
	static bool result;

	result = this->getRawBits() == n.getRawBits();
	return (result);
}

bool Fixed::operator>= (const Fixed &n)
{
	static bool result;

	result = this->getRawBits() >= n.getRawBits();
	return (result);
}

bool Fixed::operator!= (const Fixed &n)
{
	static bool result;

	result = this->getRawBits() != n.getRawBits();
	return (result);
}

//Transportation
std::ostream	&operator << (std::ostream &out, const Fixed &n)
{
	out << n.toFloat();
	return (out);
}

//Mathematical
float Fixed::operator + (const Fixed &n)
{
	float result;

	result = this->toFloat() + n.toFloat();
	return (result);
}

float Fixed::operator - (const Fixed &n)
{
	float result;

	result = this->toFloat() - n.toFloat();
	return (result);
}

float Fixed::operator * (const Fixed &n)
{
	float result;

	result = this->toFloat() * n.toFloat();
	return (result);
}

float Fixed::operator / (const Fixed &n)
{
	float result;

	result = this->toFloat() / n.toFloat();
	return (result);
}

//In/decrement
Fixed	&Fixed::operator++ ( void )
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed	Fixed::operator++ ( int )
{
	Fixed temp(*this);

	++(*this);
	return (temp);
}

Fixed	&Fixed::operator-- ( void )
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed	Fixed::operator-- ( int )
{
	Fixed temp(*this);

	--(*this);
	return (temp);
}

//Static functions
Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a <= b)
		return (a);
	return (b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if ((Fixed)a <= (Fixed)b)
		return (a);
	return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a <= b)
		return (b);
	return (a);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if ((Fixed)a <= (Fixed)b)
		return (b);
	return (a);
}