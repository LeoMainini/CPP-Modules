#ifndef SCALAR_CONVERTER_H
# define SCALAR_CONVERTER_H
#include <iostream>
#include <string.h>

using namespace std;

class ScalarConverter {

	public:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &scc);
		ScalarConverter &operator = (const ScalarConverter &cca);
		static void	converter(string &exp);
};

#endif