#ifndef MUTANT_STACK_H
#define MUTANT_STACH_H
#include <stack>
#include <list>
#include <iostream>
#include <deque>

template <class T, class C=std::deque<T> >
class MutantStack: public std::stack<T, C>
{
	public:
		typedef typename C::iterator iterator;
		iterator begin() { return (this->c.begin()); }
		iterator end() { return (this->c.end()); }
};

#endif