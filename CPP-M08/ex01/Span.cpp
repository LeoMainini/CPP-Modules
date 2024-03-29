#include "Span.hpp"
#include <algorithm>
#include <numeric>
#include <cstdlib>

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

bool Span::empty(){
	return (_numbers.empty());
}

std::ostream &operator<<(std::ostream &o, Span &span)
{
	if (span.empty())
		return (o);
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

void rAbs(int &num){
	num = abs(num);
}

void	Span::calculateSpans(){
	if (_numbers.size() < 2)
		throw (std::length_error("No spans could be found"));
	_spans.resize(_numbers.size());
	std::adjacent_difference(_numbers.begin(), _numbers.end(), _spans.begin());
	std::for_each(_spans.begin(), _spans.end(), rAbs);
}

int		Span::shortestSpan(){
	calculateSpans();
	return (*std::min_element(_spans.begin() + 1, _spans.end()));
}

int		Span::longestSpan(){
	calculateSpans();
	return (*std::max_element(_spans.begin() + 1, _spans.end()));
}

Span::~Span() {}