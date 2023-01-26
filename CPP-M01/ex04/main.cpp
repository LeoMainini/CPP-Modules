#include <iostream>
#include <fstream>
#include <sstream>

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Incorrect arguments" << std::endl;
		return (0);
	}

	std::ifstream	file;
	std::string		text;
	std::string		line;

	file.open(argv[1]);
	if (!file.is_open())
	{
		std::cout << "File not found" << std::endl;
		return (1);
	}
	while(std::getline(file, line))
		text.append(line).append("\n");
	file.close();

	int	i = 0;
	unsigned int position = 0;
	std::string		out_name(argv[1]);
	std::ofstream	outfile(out_name.append(".replace").c_str());
	std::string		needle(argv[2]);

	if (!outfile.is_open())
		std::cout << "File creation failed" << std::endl;
	while ((position = text.find(needle, i)) < text.length() && outfile.is_open())
	{
		outfile << text.substr(i, position - i);
		outfile << argv[3];
		i = position + needle.length();
	}
	if (i < (int)(text.length() - needle.length()) && outfile.is_open())
		outfile << &text.c_str()[i + needle.length()];
	outfile.close();
}
