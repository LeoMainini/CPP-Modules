#ifndef MUTANT_STACK_H
#define MUTANT_STACH_H
#include <stack>
#include <list>
#include <iostream>
#include <deque>

template <class T>
class MutantStack: public std::stack<T, std::deque<T> >
{
	protected:
		typedef std::stack<T, std::deque<T> > base_s;
	public:
		typedef typename base_s::value_type value_type;
		typedef typename base_s::container_type container_type;
		typedef typename base_s::size_type size_type;

		using base_s::empty;
		using base_s::size;
		using base_s::top;
		using base_s::push;
		// using base_s::emplace;
		// using base_s::swap;
		using base_s::pop;

};

#endif