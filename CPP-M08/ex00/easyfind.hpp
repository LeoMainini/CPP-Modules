#include <iostream>
#include <algorithm>
#include <iterator>

template <typename T>
typename T::iterator easyfind(T &c, int entry){
	typename T::iterator entryIt = std::find(c.begin(), c.end(), entry);
	if (entryIt == c.end())
		throw (std::out_of_range("number not in container"));
	return (entryIt);

}