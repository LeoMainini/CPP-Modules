#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	BitcoinExchange beDB;
	
	if (argc != 2)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		return (1);
	}
	beDB.printCalcdOutput(argv[argc - 1]);
}