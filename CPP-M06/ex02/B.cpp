#include "B.hpp"
#include "colors.h"
#include <iostream>

B::B(): Base(){
	std::cout << Brown << "Constructed new B instance" << NC << std::endl;
}

B::~B(){}