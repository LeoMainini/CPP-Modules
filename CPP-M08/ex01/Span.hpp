#ifndef SPAN_H
#define SPAN_H
#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
private:
	unsigned int	_size;
	std::vector<int> _numbers;
	std::vector<int> _spans;
	Span();
	void calculateSpans();

public:
	//Constructors
	Span(unsigned int size);
	Span(const Span &copy);
	Span	&operator= (const Span &assign);
	~Span();
	//Getters and Setters
	int back();
	bool empty();
	unsigned int	get_size();
	void	addNumber(int number);
	unsigned int	get_max_size();
	void	addNumbers(int number[]);
	std::vector<int>::iterator end();
	std::vector<int>::iterator begin();
	//Span Functions
	int		shortestSpan();
	int		longestSpan();
	//Setter templates
	template <typename numContainer>
	void	addNumbers(const numContainer &numbers)
	{
		if (_numbers.size() + numbers.size() > _size)
			throw (std::out_of_range("Span is full"));
		unsigned int oldSize = _numbers.size(); 
		_numbers.resize(_numbers.size() + numbers.size());
		std::copy(numbers.begin(), numbers.end(), _numbers.begin() + oldSize);
	}
};
//Stream overloads
std::ostream &operator<<(std::ostream &o, Span &span);

#endif