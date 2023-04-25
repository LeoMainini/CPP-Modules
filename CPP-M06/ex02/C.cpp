#include "C.hpp"
#include "colors.h"
#include <iostream>

using namespace std;

C::C(): Base(){
	cout << Brown << "Constructed new C instance" << NC << endl;
}

C::~C(){}