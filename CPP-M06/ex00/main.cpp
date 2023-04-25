#include "ScalarConverter.hpp"
#include "colors.h"



int	main(int argc, char **argv)
{
	std::string expression;
	if (argc < 2)
	{
		std::cout << LightRed << "Insuficient arguments" << NC << std::endl;
	}
	for (int i = 1; i < argc && argv[i]; i++)
	{
		expression = argv[i];
		ScalarConverter::converter(expression);	
	}
}