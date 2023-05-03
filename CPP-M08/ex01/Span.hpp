#ifndef SPAN_H
#define SPAN_H
#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
private:
	unsigned int	_size;
	Span();
	std::vector<int> _numbers;

public:
	//Constructors
	Span(unsigned int size);
	Span(const Span &copy);
	Span	&operator= (const Span &assign);
	~Span();
	//Functions
	void	addNumber(int number);
	int		shortestSpan();
	int		longestSpan();
	std::vector<int>::iterator begin();
	std::vector<int>::iterator end();
	int back();
	unsigned int	get_max_size();
	unsigned int	get_size();
	template <typename numContainer>
	void	addNumbers(const numContainer &numbers)
	{
		if (_numbers.size() + numbers.size() > _size)
			throw (std::out_of_range("Span is full"));
		unsigned int oldSize = _numbers.size(); 
		_numbers.resize(_numbers.size() + numbers.size());
		std::copy(numbers.begin(), numbers.end(), _numbers.begin() + oldSize);
	}
	void	addNumbers(int number[]);
};

std::ostream &operator<<(std::ostream &o, Span &span);

#endif