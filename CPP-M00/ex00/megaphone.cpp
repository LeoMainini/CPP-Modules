#include <iostream>

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBREARABLE FEEDBACK NOISE *";
	for (int i = 1; i < argc && argc > 1; i++)
		for(int	j = 0; argv[i][j]; j++)
			std::cout << (char)toupper(argv[i][j]);
	std::cout << std::endl;
}