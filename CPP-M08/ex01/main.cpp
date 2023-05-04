#include "Span.hpp"
#include <stdlib.h>
#include <time.h>

int main(void)
{
	Span a(10001);
	int	nums[] = {7, 9, 1, -5, 6};
	std::vector<int> vec(nums, nums + sizeof(nums) / sizeof(int));
	srand(time(NULL));

	std::cout << "at start a = " << a << std::endl;
	a.addNumber(5);
	a.addNumber(6);
	a.addNumber(7);
	a.addNumber(8);
	a.addNumber(9);
	a.addNumber(10);
	a.addNumber(15);
	a.addNumber(16);
	a.addNumber(11);
	a.addNumbers(vec);
	a.addNumber(16);
	a.addNumber(11);
	for (int i = 0; i < 9985; i++)
		a.addNumber(rand() % 400 - 200 );
	std::cout << "Span a = " << a << std::endl;
	try {
		a.addNumbers(nums);
		std::cout << "Numbers added, new span a = " << a << std::endl;
	} catch (std::exception &e){
		std::cout << "Error addind numbers: " << e.what() << ".\nCurrent span value = "
			<< a << ", max size = " << a.get_max_size() << ", current size = " << a.get_size()
			<< std::endl;
	}

	std::cout << "Longest span = " << a.longestSpan() << ", shortest span = " << a.shortestSpan() << std::endl;
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
}