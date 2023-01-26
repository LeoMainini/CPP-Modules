#include <iostream>

int	main( void )
{
	std::string str = "HI THIS IS BRAIN";
	std::string	&stringREF = str;
	std::string	*stringPTR;

	stringPTR = &str;
	std::cout << "str adresss: " << &str << std::endl << "address held by strPTR:" << stringPTR
		<< std::endl << "address help by strREF: " << &stringREF << std::endl;
	std::cout << "str value: " << str << std::endl << "value pointed to by strPTR:" << *stringPTR
		<< std::endl << "value pointed to by strREF: " << stringREF << std::endl;
}