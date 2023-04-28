#include "Array.hpp"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#define MAX_VAL 750
#define PRINT   0

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
		for (int i = 0; i < MAX_VAL; i++)
		{
			if (tmp[i] != numbers[i] || tmp[i] != test[i] || test[i] != numbers[i])
				std::cout << "Failed copying items" << std::endl;
		}
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
		std::cout << "ACCEPTED INDEXER" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
	try
    {
        numbers[MAX_VAL - 1] = 0;
		std::cout << "ACCEPTED INDEXER" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
		std::cout << "ACCEPTED INDEXER" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
		if (PRINT)
		{
			std::cout << std::setw(10) << std::left << numbers[i];
			if (i % 8 == 0 || i == MAX_VAL -1)
				std::cout << std::endl;
			else
				std::cout << " | ";
		}
	}
    delete [] mirror;//
    return 0;
}
