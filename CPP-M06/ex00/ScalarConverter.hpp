#ifndef SCALAR_CONVERTER_H
# define SCALAR_CONVERTER_H
#include <iostream>
#include <string.h>



class ScalarConverter {

	private:
		static float	fValue;
		static double	dValue;
		static int		iValue;
		static char		cValue;
		static std::string	get_type(std::string &exp);
		static void	int_converter(std::string &exp);
		static void	char_converter(std::string &exp);
		static void	float_converter(std::string &exp);
		static void	double_converter(std::string &exp);
		static void convert_to_n(std::string &exp, int type_i);

	public:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &scc);
		ScalarConverter &operator = (const ScalarConverter &cca);
		static void	converter(std::string &exp);
};

#endif