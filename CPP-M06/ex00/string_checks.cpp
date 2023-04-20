#include <iostream>

using namespace std;

int		valid_num_str(string &exp)
{
	int	not_exponent = 1;
	//error out on non numeric expression
	if (exp.find_first_not_of("0123456789.f-e+") != string::npos)
		return (0);
	//check if exponent and error out if no numbers before or only numbers before
	if(exp.find_first_of("e") != string::npos)
		not_exponent = 0;
	//errpr out on multiple exponents or if no numbers either side of it
	if(!not_exponent
		&& (exp.find_first_of("0123456789") > exp.find_first_of("e")
		|| exp.find_last_of("0123456789+") < exp.find_first_of("e")
		|| exp.find_first_of("e") != exp.find_last_of("e")))
		return (0);
	//error out on multiple - or numbers pre - or if exponent on multiple - after the first or if numbers before first
	if (not_exponent && exp.find_first_of("-+") != string::npos
		&& ((exp.find_first_of("-+") != exp.find_last_of("-+"))
		|| exp.find_first_of("0123456789") < exp.find_first_of("-+")))
		return (0);
	//error out if more neg or pos sines arround exponent than 1 behind number
	if (!not_exponent && exp.find_first_of("-+", 1) != string::npos
		&& (exp[exp.find_first_of("-+", 1) - 1] != 'e'
		|| exp.find_first_of("-+", 1) != exp.find_last_of("-+")
		|| exp.find_last_of("0123456789") < exp.find_first_of("-+")))
		return (0);
	// //error out on multiple . or dots before numbers with no precedent
	if (exp.find_first_of('.') != string::npos
		&& (exp.find_first_of('.') != exp.find_last_of(".")
		|| exp.find_first_of("0123456789") > exp.find('.')))
		return (0);
	//error out on multiple f or f not last or no decimal part
	if (exp.find_first_of("f") != string::npos
		&& (exp.find_first_of(".e") == string::npos
		|| exp.find_first_of("f") != exp.find_last_of("f")
		|| exp.find_last_of("0123456789") > exp.find_first_of("f")))
		return (0);
	//if all conditions fail its a valid string
	return (1);
}

string	get_type(string &exp)
{
	//int neg = exp[0] == '-' ? 1 : 0;
	if (exp[0] == 0 || ((exp[0] > 0 && ((exp[0] < '0') || (exp[0] > '9')))
			&& !exp[1]))
		return ("char");
	if (!exp.compare("-inff") || !exp.compare("inff") || !exp.compare("nanf"))
		return ("float");
	if (!exp.compare("-inf") || !exp.compare("inf") || !exp.compare("nan"))
		return ("double");
	if (!valid_num_str(exp))
		return ("undefined");
	else if (exp.find_first_of(".e") == string::npos)
		return ("int");
	else if (exp.find_first_of("f") == string::npos)
		if (exp.find_last_of("0123456789") < exp.find('.'))
			return ("undefined");
		else
			return ("double");
	else
		return ("float");
}

//validated
void	format_str(string &exp)
{
	int	i;

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
	for (i = 0; exp[i]; i++)
		if (exp[i] >= 'A' && exp[i] <= 'Z')
			exp[i] += 'a' - 'A';
}
