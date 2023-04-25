#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>
#include "colors.h"


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
		std::cout << Cyan << "Pointer is of child class type" << LightCyan << " A" << NC << std::endl;
	if (dynamic_cast<B *>(p))
		std::cout << Cyan << "Pointer is of child class type" << LightCyan << " B" << NC << std::endl;
	if (dynamic_cast<C *>(p))
		std::cout << Cyan << "Pointer is of child class type" << LightCyan << " C" << NC << std::endl;
}

void identify(Base& p)
{
	try{
		dynamic_cast<A &>(p);
		std::cout << Red << "Pointer is of child class type" << LightRed << " A" << NC << std::endl;
		return ;
	} catch (std::exception &e){}
	try{
		dynamic_cast<B &>(p);
		std::cout << Red << "Pointer is of child class type" << LightRed << " B" << NC << std::endl;
		return ;
	} catch (std::exception &e){}
	try{
		dynamic_cast<C &>(p);
		std::cout << Red << "Pointer is of child class type" << LightRed << " C" << NC << std::endl;
		return ;
	} catch (std::exception &e){}
}

int main(void){
	Base *instancePtr = generate();
	identify(instancePtr);
	identify(*instancePtr);
	delete instancePtr;
}