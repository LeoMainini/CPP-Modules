#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Error: Insufficient arguments" << std::endl;
		return (1);
	}
	PmergeMe sorter(++argv);
	sorter.runTest();
	// sorter.sortVector();
	// sorter.sortList();
	return (0);
}