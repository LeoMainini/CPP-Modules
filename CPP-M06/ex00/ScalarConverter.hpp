#ifndef SCALAR_CONVERTER_H
# define SCALAR_CONVERTER_H
#include <iostream>
#include <string.h>

using namespace std;

class ScalarConverter {

	private:
		static float	fValue;
		static double	dValue;
		static int		iValue;
		static char		cValue;
		static void	convert(int i);
		static void	convert(char c);
		static void	convert(float f);
		static void	convert(double d);
		static void	int_converter(string &exp);
		static void	float_converter(string &exp);
		static void	double_converter(string &exp);
		static void convert_to_n(string &exp, int type_i);

	public:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &scc);
		ScalarConverter &operator = (const ScalarConverter &cca);
		static void	converter(string &exp);
};

#endif