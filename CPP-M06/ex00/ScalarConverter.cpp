/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:21:46 by leferrei          #+#    #+#             */
/*   Updated: 2023/04/20 23:03:43 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <climits>
#include <errno.h>
#include <iomanip>
#include <stdlib.h>
#include <float.h>
#include <cmath>
#include "colors.h"
#include "string_checks.hpp"
#include "ScalarConverter.hpp"

using namespace std;
float	ScalarConverter::fValue;
double	ScalarConverter::dValue;
int		ScalarConverter::iValue;
char	ScalarConverter::cValue;

static	void	error(string &exp, string type)
{
	cout << LightRed << " Error: " << NC << exp << " out of range <" << type << ">" << endl;
}

void	ScalarConverter::char_converter(string &exp)
{
	cout << "char: ";
	isprint(exp[0]) ? cout << '\'' << exp[0] << '\'' : cout << "Non displayable";
	cout << endl;
	cout << "iValue: " << static_cast<int>(exp[0]) << endl;
	cout << "float: " << setprecision(1) << static_cast<float>(exp[0]) << 'f' << endl;
	cout << "double: " << setprecision(1) << static_cast<double>(exp[0]) << endl;
}

void	ScalarConverter::int_converter(string &exp)
{
	long	test = atol(exp.c_str());
	if (test > INT_MAX || test < INT_MIN)
		return (error(exp, "int"));
	iValue = atoi(exp.c_str());
	cout << "char: ";
	(iValue < CHAR_MAX && iValue >= 0) ?
		isprint(iValue) ? cout << '\'' << static_cast<char>(iValue) << '\'' : cout << "Non displayable" : cout << "Impossible";
	cout << endl;
	cout << "int: " << iValue << endl;
	cout << "float: " << setprecision(1) << static_cast<float>(iValue) << 'f' << endl;
	cout << "double: " << setprecision(1) << static_cast<double>(iValue) << endl;
}

void	ScalarConverter::float_converter(string &exp)
{
	fValue = strtof(exp.c_str(), 0);
	if (errno == ERANGE)
		return (error(exp, "float"));
	cout << "char: ";
	(fValue < CHAR_MAX && fValue >= 0) ?
		isprint(floor(fValue)) ? cout << '\'' << static_cast<char>(fValue) << '\'' : cout << "Non displayable" : cout << "Impossible";
	cout << endl;

	cout << "int: ";
	(fValue < INT_MAX && fValue > INT_MIN) ? cout << static_cast<int>(fValue) : cout << "Impossible";
	cout << endl;

	cout << "float: " << setprecision(1) << fValue << 'f' << endl;

	cout << "double: " <<  setprecision(1) << static_cast<double>(fValue) << endl;

}


void	ScalarConverter::double_converter(string &exp)
{
	
	dValue = strtod(exp.c_str(), 0);
	if (errno == ERANGE)
		return (error(exp, "double"));

	cout << "char: ";
	(dValue < CHAR_MAX && dValue >= 0) ?
		isprint(floor(dValue)) ? cout << '\'' << static_cast<char>(dValue) << '\'' : cout << "Non displayable" : cout << "Impossible";
	cout << endl;

	cout << "int: ";
	(dValue < INT_MAX && dValue > INT_MIN) ? cout << static_cast<int>(dValue) : cout << "Impossible";
	cout << endl;

	cout << "float: ";
	strtof(exp.c_str(), 0);
	errno != ERANGE ? cout << setprecision(1) << static_cast<float>(dValue) << 'f': cout << "Impossible";
	cout << endl;

	cout << "double: " << setprecision(1) << (dValue) << endl;
}
void	ScalarConverter::convert_to_n(string &exp, int type_i)
{
	switch (type_i)
	{
	case 0:
		char_converter(exp);
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
		cout << LightRed << " Error: " << NC << "expression \'" << exp << "\' unrecognized" << endl;
		break;
	}
}

void	ScalarConverter::converter(string &exp)
{
	static string	types[4] = {"char", "int", "float", "double"};
	int				type_i = -1;
	cout << fixed;
	format_str(exp);
	string	type = get_type(exp);
	for (int i = 0; i < 4; i++) 
		if (!type.compare(types[i]))
			type_i = i;
	convert_to_n(exp, type_i);	
}