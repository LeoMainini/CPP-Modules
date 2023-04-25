#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>
#include "colors.h"

using namespace std;

Base *generate(void){
	srand((unsigned)time(NULL));
	switch (rand() % 3){
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
	}
	return (new A());
}

void identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		cout << Cyan << "Pointer is of child class type" << LightCyan << " A" << NC << endl;
	if (dynamic_cast<B *>(p))
		cout << Cyan << "Pointer is of child class type" << LightCyan << " B" << NC << endl;
	if (dynamic_cast<C *>(p))
		cout << Cyan << "Pointer is of child class type" << LightCyan << " C" << NC << endl;
}

// void identify(Base& p)
// {

// }

int main(void){
	Base *instancePtr = generate();
	identify(instancePtr);
	// identify(*instancePtr);
	delete instancePtr;
}