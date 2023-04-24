#include "B.hpp"
#include "colors.h"
#include <iostream>

using namespace std;

B::B(): Base(){
	cout << Brown << "Constructed new B instance" << NC << endl;
}