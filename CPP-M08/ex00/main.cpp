#include "easyfind.hpp"
#include <list>
#include <vector>

int	main(void){
	int intList[] = {5, 6, 6, 7 ,78, 8 ,9, 8 ,11, 10};
	std::vector<int> listInts(intList, intList + sizeof(intList) / sizeof(int));
	::easyfind(listInts, 8);
	std::cout << *::easyfind(listInts, 8) << std::endl;
}