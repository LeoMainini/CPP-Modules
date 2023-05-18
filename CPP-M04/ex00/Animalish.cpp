
#include "Animalish.hpp"

Animalish::Animalish( void ){}

Animalish::Animalish(const Animalish &a)
{
	*this = a;
}

Animalish &Animalish::operator= (const Animalish &a)
{
	if (this != &a)
		_type = a._type;
	return (*this);
}

Animalish::~Animalish( void ) {}

const std::string &Animalish::get_type( void ) const { return (_type); }

void	Animalish::makeSound( void ) const 
{
	if (_type == "DogInDisguise")
		std::cout << "WOO.. *cough couch* miiaaawuuuuF" << std::endl;
}
