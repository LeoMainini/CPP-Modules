#include "ScalarConverter.hpp"
#include "colors.h"

using namespace std;

int	main(int argc, char **argv)
{
	string expression;
	if (argc < 2)
	{
		cout << LightRed << "Insuficient arguments" << NC << endl;
	}
	for (int i = 1; i < argc && argv[i]; i++)
	{
		expression = argv[i];
		ScalarConverter::converter(expression);	
	}
}