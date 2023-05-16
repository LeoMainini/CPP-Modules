#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

std::string get_file_text(std::string filename)
{
	std::ifstream	file;
	std::string		text, line;

	file.open(filename.c_str());
	if (file.fail()) {
		std::cout << "File not found" << std::endl;
		exit (1);
	}
	while(std::getline(file, line))
		text.append(line).append("\n");
	file.close();
	return (text);
}

void	replace_text_output(std::string text, std::string filename, std::string needle, std::string replcmnt)
{
	int				i = 0;
	unsigned int	position = 0;
	std::ofstream	outfile(filename.append(".replace").c_str());

	if (outfile.fail())
		std::cout << "File creation failed" << std::endl;
	while ((position = text.find(needle, i)) < text.length() && outfile.is_open())
	{
		outfile << text.substr(i, position - i);
		outfile << replcmnt;
		i = position + needle.length();
	}
	if (i < (int)(text.length() - needle.length()) && outfile.is_open())
		outfile << &text.c_str()[i + needle.length()];
	outfile.close();
}

int	main(int argc, char **argv)
{
	std::string		text;

	if (argc != 4)
	{
		std::cout << "Incorrect arguments" << std::endl;
		return (0);
	}
	text = get_file_text(argv[1]);
	replace_text_output(text, argv[1], argv[2], argv[3]);
}
