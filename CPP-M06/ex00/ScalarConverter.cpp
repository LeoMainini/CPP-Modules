#include <climits>
#include <errno.h>
#include <stdlib.h>
#include "string_checks.hpp"
#include "ScalarConverter.hpp"

using namespace std;
float	ScalarConverter::fValue;
double	ScalarConverter::dValue;
int		ScalarConverter::iValue;
char	ScalarConverter::cValue;

void	ScalarConverter::int_converter(string &exp)
{
	long	test = atol(exp.c_str());
	if (test > INT_MAX || test < INT_MIN)
		double_converter(exp);
	ScalarConverter::iValue = atoi(exp.c_str());
	//converter func
	cout << "iValue = " << iValue << endl;
}

void	ScalarConverter::float_converter(string &exp)
{
	
	ScalarConverter::fValue = strtof(exp.c_str(), 0);
	if (errno == ERANGE) {}
		//print error func
	//converter func
	cout << "fValue = " << fValue << endl;
}


void	ScalarConverter::double_converter(string &exp)
{
	
	ScalarConverter::dValue = strtof(exp.c_str(), 0);
	if (errno == ERANGE){}
		//print error func
	//converter func
	cout << "dValue = " << ScalarConverter::dValue << endl;
}
void	ScalarConverter::convert_to_n(string &exp, int type_i)
{
	switch (type_i)
	{
	case 0:
		//convert(exp[0]);
		//converter func - see intra videos
		break;
	case 1:
		int_converter(exp);
		break;
	case 2:
		float_converter(exp);
		break;
	case 3:
		double_converter(exp);
		break;
	default:
		//print error func
		break;
	}
}

void	ScalarConverter::converter(string &exp)
{
	static string	types[4] = {"char", "int", "float", "double"};
	int				type_i = -1;

	format_str(exp);
	string	type = get_type(exp);
	for (int i = 0; i < 4; i++) 
		if (!type.compare(types[i]))
			type_i = i;
	// if (type_i == -1)
	// 	return (impossible func);
	convert_to_n(exp, type_i);
	cout <<  type << endl;
	
}