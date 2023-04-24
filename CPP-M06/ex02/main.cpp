#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include<iostream>

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

int main(void){
	Base *instancePtr = generate();
	(void)instancePtr;
	delete instancePtr;
}