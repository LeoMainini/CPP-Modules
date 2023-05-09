#include "RPN.hpp"

int main( int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: incorrect number of arguments" << std::endl;
		return (1); 
	}
	RPN::calculateExpression(argv[1]);
}