#include "A.hpp"
#include "colors.h"
#include <iostream>

A::A(): Base(){
	std::cout << Brown << "Constructed new A instance" << NC << std::endl;
}

A::~A(){}