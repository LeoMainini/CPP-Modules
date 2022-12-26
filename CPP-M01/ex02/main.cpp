#include <iostream>

int	main( void )
{
	std::string str = "HI THIS IS BRAIN";
	std::string	&stringREF = str;
	std::string	*stringPTR;

	stringPTR = &str;
	std::cout << "str adresss: " << &str << "; adress held by strPTR:" << stringPTR
		<< "; adress help by strREF: " << &stringREF << std::endl;
	std::cout << "str value: " << str << "; value pointed to by strPTR:" << *stringPTR
		<< "; value pointed to by strREF: " << stringREF << std::endl;
}