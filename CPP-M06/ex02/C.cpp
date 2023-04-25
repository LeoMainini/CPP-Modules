#include "C.hpp"
#include "colors.h"
#include <iostream>

C::C(): Base(){
	std::cout << Brown << "Constructed new C instance" << NC << std::endl;
}

C::~C(){}