#include "MutantStack.hpp"

int main(void)
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
		return 0;
	}
}