#include "templates.hpp"
#include <iostream>

int main(void){
	std::string a = "ola";
	std::string b = "adeus";
	std::cout << ::max(5, 7) << std::endl;
	std::cout << ::min(a, b) << std::endl;
	std::cout << ::min(5, 7) << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	::swap(a, b);
	std::cout << a << std::endl;
	std::cout << b << std::endl;
}