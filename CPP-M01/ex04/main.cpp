#include <iostream>
#include <fstream>
#include <sstream>

int	main(int argc, char **argv)
{
	std::ifstream	file;
	std::string		text;
	std::string		line;

	if (argc != 4)
	{
		std::cout << "Incorrect arguments" << std::endl;
		return (0);
	}
	file.open(argv[1]);
	if (!file.is_open())
		return (1);
	while(std::getline(file, line))
		text.append(line).append("\n");
	file.close();
	std::cout << text << std::endl;	
}
