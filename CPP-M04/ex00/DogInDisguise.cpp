#include "DogInDisguise.hpp"

DogInDisguise::DogInDisguise( void ): Animalish(){
	this->_type = "DogInDisguise";
}
DogInDisguise::DogInDisguise( const DogInDisguise &a) { 
	*this = a;
}
DogInDisguise &DogInDisguise::operator = (const DogInDisguise &a) {
	if (this != &a)
		Animalish::_type = a.get_type();
	return (*this);
}
DogInDisguise::~DogInDisguise( void ) { }