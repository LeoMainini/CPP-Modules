#include "iter.hpp"
#include "templates.hpp"
#include <iostream>

void	rot_13(std::string &str)
{
	for (std::string::iterator c = str.begin(); c != str.end(); c++)
	{
		if ((*c > 'a' && *c < 'z' && *c < 'a' + 13 )
			|| (*c > 'A' && *c < 'Z' && *c < 'A' + 13))
			*c = *c + 13;
		else if ((*c > 'a' && *c < 'z') || (*c > 'A' && *c < 'Z'))
			*c = *c - 13;
	}
}

int main(void){
	std::string a[] = {"scandinavia", "porugal", "scotland", "italy"};
	int			b[] = {1, 2, 3, 4, 5, 6, 7, 8};
	::iter(&a, 4, &::printa);
	::iter(&a, 4, &rot_13);
	::iter(&a, 4, &::printa);
	::iter(&b, 8, &::printa);
}