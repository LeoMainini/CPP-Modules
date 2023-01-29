#include "Harl.hpp"
#include <iostream>

// int	main( void  )
// {
// 	Harl harl;

// 	harl.complain("Out of bounds");
// 	std::cout << std::endl;
// 	harl.complain("DEBUG");
// 	std::cout << std::endl;
// 	harl.complain("INFO");
// 	std::cout << std::endl;
// 	harl.complain("WARNING");
// 	std::cout << std::endl;
// 	harl.complain("ERROR");
// 	std::cout << std::endl;
// }

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Invalid arguments" << std::endl;
		return (0);
	}
	Harl harl;

	harl.complain(argv[1]);
}


