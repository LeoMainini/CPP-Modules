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
	int	not_exponent = 1;
	//error out on non numeric expression
	if (exp.find_first_not_of("0123456789.fF-eE+") != string::npos)
		return (0);
	//check if exponent and error out if no numbers before or only numbers before
	if(exp.find_first_of("eE") != string::npos)
		not_exponent = 0;
	//errpr out on multiple exponents or if no numbers either side of it
	if(!not_exponent
		&& (exp.find_first_of("0123456789") > exp.find_first_of("eE")
		|| exp.find_last_of("0123456789+") < exp.find_first_of("eE")
		|| exp.find_first_of("eE") != exp.find_last_of("eE")))
		return (0);
	//error out on multiple - or numbers pre - or if exponent on multiple - after the first or if numbers before first
	if (not_exponent && exp.find_first_of("-+") != string::npos
		&& ((exp.find_first_of("-+") != exp.find_last_of("-+"))
		|| exp.find_first_of("0123456789") < exp.find_first_of("-+")))
		return (0);
	//error out if more neg or pos sines arround exponent than 1 behind number
	if (!not_exponent && exp.find_first_of("-+", 1) != string::npos
		&& (exp[exp.find_first_of("-+", 1) - 1] != 'e'
		|| exp.find_first_of("-+", 1) != exp.find_last_of("-+")))
		return (0);
	// //error out on multiple . or dots before numbers with no precedent
	if (exp.find_first_of('.') != string::npos
		&& (exp.find_first_of('.') != exp.find_last_of(".")
		|| exp.find_first_of("0123456789") > exp.find('.')))
		return (0);
	//error out on multiple f or f not last or no decimal part
	if (exp.find_first_of("fF") != string::npos
		&& (exp.find_first_of(".eE") == string::npos
		|| exp.find_first_of("fF") != exp.find_last_of("fF")
		|| exp.find_last_of("0123456789") > exp.find_first_of("fF")))
		return (0);
	//if all conditions fail its a valid string
	return (1);
}

static string	get_type(string &exp, double &value)
{
	//int neg = exp[0] == '-' ? 1 : 0;
	char *end;
	if (exp[0] == 0 || ((exp[0] > 0 && ((exp[0] < '0') || (exp[0] > '9')))
			&& !exp[1]))
		return ("char");
	if (!valid_num_str(exp))
		return ("undefined");
	if (exp.find_first_of(".eE") == string::npos)
		return ("int");
	else if (exp.find_first_of("fF") == string::npos)
		return ("double");
	else
		return ("float");
	value = strtod(exp.c_str(), &end);
	return ("undefined");
}

//validated
static void	format_str(string &exp)
{
	int	i;
	// float b = 58.e5;
	// b = 1000.0f;

	i = 0;
	while (exp[i] && (exp[i] == ' ' || exp[i] == '	'))
		i++;
	if (i == (int)exp.length())
	{
		exp = "";
		return ;
	}
	exp = exp.substr(i, exp.length() - i);
	i = exp.length() - 1;
	while (i > 0 && (exp[i] == ' ' || exp[i] == '	'))
		i--;
	exp = exp.substr(0, i + 1);
}

void	ScalarConverter::converter(string &exp)
{
	double		value = 0;
	format_str(exp);
	string	type = get_type(exp, value);
	cout << exp << " = " << value <<endl;
	cout <<  type << endl;
	
}