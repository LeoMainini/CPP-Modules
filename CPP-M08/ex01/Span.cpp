#include "Span.hpp"
#include <algorithm>

Span::Span(unsigned int size): _size(size) { }



void	Span::addNumber(int number){
	if (_numbers.size() >= _size)
		throw (std::out_of_range("Span is full"));
	_numbers.push_back(number);
}

void	Span::addNumbers(int numbers[]){
	std::vector<int> to_copy(*numbers, *numbers + sizeof(*numbers) / sizeof(int));
	addNumbers(to_copy);
}
std::vector<int>::iterator Span::begin(){
	return (_numbers.begin());
}

std::vector<int>::iterator Span::end(){
	return (_numbers.end());
}
int Span::back(){
	return (_numbers.back());
}

std::ostream &operator<<(std::ostream &o, Span &span)
{
	o << "{";
	for (std::vector<int>::iterator s = span.begin(); s + 1 < span.end(); s++)
		o << " " << *s <<",";
	o << " " << span.back() << " }";
	return (o);
}

unsigned int	Span::get_max_size(){
	return (_size);
}

unsigned int	Span::get_size(){
	return (_numbers.size());
}

Span::~Span() {}