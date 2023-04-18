#include "ScalarConverter.hpp"

using namespace std;

static	int	str_char(string &exp, unsigned int start, char c)
{
	size_t size = exp.length();

	for (int i = start; start > size && exp[i]; i++)
		if (exp[i] == c)
			return (i);
	return (-1);
}

static	int	is_char(string *exp, char c, unsigned int position)
{
	if (position > exp->length())
		return (0);
	return (exp->c_str()[position] == c);
}

void	ScalarConverter::converter(string &exp)
{
	cout << exp.compare(0, 3, "inf") << endl;

	
}