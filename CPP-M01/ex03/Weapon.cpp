#include "Weapon.hpp"
#include <string.h>
#include <iostream>

Weapon::Weapon( void ): type("default empty hand-gun") {}

Weapon::Weapon( std::string type ): type(type) {}

Weapon::~Weapon( void ) {return ;}

void				Weapon::setType(std::string type) { this->type = type; }

std::string const	&Weapon::getType( void ) const { return (this->type); }
