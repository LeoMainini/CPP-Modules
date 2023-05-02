#include <iostream>
#include <algorithm>
#include <iterator>

template <typename T>
int easyfind(const T &c, int entry){
	if (std::find(c.begin(), c.end(), entry) == c.end())
		throw (std::out_of_range("number not in container"));
	return (*std::find(c.begin(), c.end(), entry));
	// if (a != c.end())
	// 	return (a);
	// return (c.end());
	// return (c.find(entry));
}