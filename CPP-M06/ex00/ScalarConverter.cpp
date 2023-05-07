/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:21:46 by leferrei          #+#    #+#             */
/*   Updated: 2023/05/07 04:16:04 by leferrei         ###   ########.fr       */
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


float	ScalarConverter::fValue;
double	ScalarConverter::dValue;
int		ScalarConverter::iValue;
char	ScalarConverter::cValue;

static	void	error(std::string &exp, std::string type)
{
	std::cout << LightRed << " Error: " << NC << exp << " out of range <" << type << ">" << std::endl;
}

void	ScalarConverter::char_converter(std::string &exp)
{
	std::cout << "char: ";
	isprint(exp[0]) ? std::cout << '\'' << exp[0] << '\'' : std::cout << "Non displayable";
	std::cout << std::endl;
	std::cout << "iValue: " << static_cast<int>(exp[0]) << std::endl;
	std::cout << "float: " << std::setprecision(1) << static_cast<float>(exp[0]) << 'f' << std::endl;
	std::cout << "double: " << std::setprecision(1) << static_cast<double>(exp[0]) << std::endl;
}

void	ScalarConverter::int_converter(std::string &exp)
{
	if (exp.length() > 11)
		return (error(exp, "int"));
	long	test = atol(exp.c_str());
	if (test > INT_MAX || test < INT_MIN)
		return (error(exp, "int"));
	iValue = atoi(exp.c_str());
	std::cout << "char: ";
	(iValue < CHAR_MAX && iValue >= 0) ?
		isprint(iValue) ? std::cout << '\'' << static_cast<char>(iValue) << '\'' : std::cout << "Non displayable" : std::cout << "Impossible";
	std::cout << std::endl;
	std::cout << "int: " << iValue << std::endl;
	std::cout << "float: " << std::setprecision(1) << static_cast<float>(iValue) << 'f' << std::endl;
	std::cout << "double: " << std::setprecision(1) << static_cast<double>(iValue) << std::endl;
}

void	ScalarConverter::float_converter(std::string &exp)
{
	fValue = strtof(exp.c_str(), 0);
	if (errno == ERANGE)
		return (error(exp, "float"));
	std::cout << "char: ";
	(fValue < CHAR_MAX && fValue >= 0) ?
		isprint(floor(fValue)) ? std::cout << '\'' << static_cast<char>(fValue) << '\'' : std::cout << "Non displayable" : std::cout << "Impossible";
	std::cout << std::endl;

	std::cout << "int: ";
	(floor(fValue) < INT_MAX && floor(fValue) > INT_MIN) ? std::cout << static_cast<int>(fValue) : std::cout << "Impossible";
	std::cout << std::endl;

	std::cout << "float: " << std::setprecision(1) << fValue << 'f' << std::endl;

	std::cout << "double: " <<  std::setprecision(1) << static_cast<double>(fValue) << std::endl;

}


void	ScalarConverter::double_converter(std::string &exp)
{
	
	dValue = strtod(exp.c_str(), 0);
	if (errno == ERANGE)
		return (error(exp, "double"));

	std::cout << "char: ";
	(dValue < CHAR_MAX && dValue >= 0) ?
		isprint(floor(dValue)) ? std::cout << '\'' << static_cast<char>(dValue) << '\'' : std::cout << "Non displayable" : std::cout << "Impossible";
	std::cout << std::endl;

	std::cout << "int: ";
	(dValue < INT_MAX && dValue > INT_MIN) ? std::cout << static_cast<int>(dValue) : std::cout << "Impossible";
	std::cout << std::endl;

	std::cout << "float: ";
	strtof(exp.c_str(), 0);
	errno != ERANGE ? std::cout << std::setprecision(1) << static_cast<float>(dValue) << 'f': std::cout << "Impossible";
	std::cout << std::endl;

	std::cout << "double: " << std::setprecision(1) << (dValue) << std::endl;
}
void	ScalarConverter::convert_to_n(std::string &exp, int type_i)
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
		std::cout << LightRed << " Error: " << NC << "expression \'" << exp << "\' unrecognized" << std::endl;
		break;
	}
}

std::string	ScalarConverter::get_type(std::string &exp)
{
	if (exp[0] == 0 || ((exp[0] > 0 && ((exp[0] < '0') || (exp[0] > '9')))
			&& !exp[1]))
		return ("char");
	if (!exp.compare("-inff") || !exp.compare("inff") || !exp.compare("nanf"))
		return ("float");
	if (!exp.compare("-inf") || !exp.compare("inf") || !exp.compare("nan"))
		return ("double");
	if (!valid_num_str(exp))
		return ("undefined");
	else if (exp.find_first_of(".e") == std::string::npos)
		return ("int");
	else if (exp.find_first_of("f") == std::string::npos)
		if (exp.find('.') != std::string::npos && exp.find_last_of("0123456789") < exp.find('.'))
			return ("undefined");
		else
			return ("double");
	else
		return ("float");
}

void	ScalarConverter::converter(std::string &exp)
{
	static std::string	types[4] = {"char", "int", "float", "double"};
	int				type_i = -1;
	std::cout << std::fixed;
	format_str(exp);
	std::string	type = get_type(exp);
	for (int i = 0; i < 4; i++) 
		if (!type.compare(types[i]))
			type_i = i;
	convert_to_n(exp, type_i);	
}

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &scc){}

ScalarConverter &ScalarConverter::operator = (const ScalarConverter &cca) { return (*this);}
