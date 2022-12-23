#include <iostream>
#include <string.h>
#include <string>
#include "Phonebook.hpp"

int	main()
{
	std::string input;
	Phonebook	db;

	while (!std::cin.eof())
	{
		std::cout << "> ";
		std::getline(std::cin, input);
		if (!input.compare("EXIT") || std::cin.eof())
			break ;
		if (!input.compare("ADD"))
			db.add();
		else if (!input.compare("SEARCH"))
			db.search();
		else
			std::cout << "Unrecognized instruction" << std::endl;
	}
}