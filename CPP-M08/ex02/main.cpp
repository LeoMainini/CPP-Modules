#include "MutantStack.hpp"
#include <list>
#include <iostream>

int main(void)
{
	std::cout << "Mutant stack\n\n";
	{

		MutantStack<int> a;

		a.push(5);
		a.push(1);
		a.push(2);
		a.push(3);
		a.push(-1);
		a.push(1);
		a.push(8);

		a.begin();
		for(MutantStack<int>::iterator it = a.begin(); it != a.end(); it++)
			std::cout << *it << std::endl;
		{
			MutantStack<int> mstack;
			mstack.push(5);
			mstack.push(17);
			std::cout << mstack.top() << std::endl;
			mstack.pop();
			std::cout << mstack.size() << std::endl;
			mstack.push(3);
			mstack.push(5);
			mstack.push(737);
			//[...]
			mstack.push(0);
			MutantStack<int>::iterator it = mstack.begin();
			MutantStack<int>::iterator ite = mstack.end();
			++it;
			--it;
			while (it != ite)
			{
			std::cout << *it << std::endl;
			++it;
			}
			std::stack<int> s(mstack);
		}
	}
	std::cout << "\nList\n\n";
	{

		std::list<int> a;

		a.push_back(5);
		a.push_back(1);
		a.push_back(2);
		a.push_back(3);
		a.push_back(-1);
		a.push_back(1);
		a.push_back(8);

		a.begin();
		for(std::list<int>::iterator it = a.begin(); it != a.end(); it++)
			std::cout << *it << std::endl;
		{
			std::list<int> mstack;
			mstack.push_back(5);
			mstack.push_back(17);
			std::cout << mstack.back() << std::endl;
			mstack.pop_back();
			std::cout << mstack.size() << std::endl;
			mstack.push_back(3);
			mstack.push_back(5);
			mstack.push_back(737);
			//[...]
			mstack.push_back(0);
			std::list<int>::iterator it = mstack.begin();
			std::list<int>::iterator ite = mstack.end();
			++it;
			--it;
			while (it != ite)
			{
			std::cout << *it << std::endl;
			++it;
			}
			std::list<int> s(mstack);
		}
	}
}