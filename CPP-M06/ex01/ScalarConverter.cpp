#include "ScalarConverter.hpp"
#include <stdlib.h>

using namespace std;

// static	int	str_char(string &exp, unsigned int start, char c)
// {
// 	size_t size = exp.length();

// 	for (int i = start; start > size && exp[i]; i++)
// 		if (exp[i] == c)
// 			return (i);
// 	return (-1);
// }

// static	int	is_char(string *exp, char c, unsigned int position)
// {
// 	if (position > exp->length())
// 		return (0);
// 	return (exp->c_str()[position] == c);
// }

static int		valid_num_str(string &exp)
{
	if (exp.find_first_not_of("0123456789.f-") != string::npos)
		return (0);
	if (exp.find_first_of('-') != exp.find_last_of('-')
		&& exp.find_first_of("0123456789") < exp.find('-'))
		return (0);
	if (exp.find_first_of('.') != exp.find_last_of(".")
		&& (exp.find_first_of("0123456789") > exp.find('.')
		|| exp.find_last_of("0123456789") < exp.find('.')))
		return (0);
	if (exp.find_first_of('f') != exp.find_last_of("f")
		&& exp.find_last_of("0123456789") > exp.find('f'))
		return (0);
	return (1);
		// && exp.find_first_of('.') == exp.find_last_of(".")
		// && exp.find_first_of('f') == exp.find_last_of("f")
		// && exp.find('f') < exp.find_last_of()
		// || exp.find_first_of('-'))
}

static string	get_type(string &exp, long &value)
{
	//int neg = exp[0] == '-' ? 1 : 0;
	if ((exp[0] >= 0 && ((exp[0] < '0') || (exp[0] > '9'))) && !exp[1])
		return ("char");
	if (!valid_num_str(exp))
		return ("undefined");

	else if (exp.find_first_not_of("-0123456789") == string::npos)
	{
		value = atol(exp.c_str());
		if (value > -2147483649 && value < 2147483648)
			return ("int");
	}
	else if (exp.find_first_not_of("-0123456789.f") == string::npos
		&& exp.find_first_of('.') == exp.find_last_of(".")
		&& exp.find_first_of('f') == exp.find_last_of("f")
		&& !exp[exp.find_last_of('f') + 1])
	{
		return ("float");
	}
	return ("undefined");

}

void	ScalarConverter::converter(string &exp)
{
	long		value = 0;
	string	type = get_type(exp, value);
	cout <<  type << endl;
	
}