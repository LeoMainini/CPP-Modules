#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>

template <class T>
class Array
{
private:
	T				*_items;
	unsigned int	_size;
public:
	//(Con/Des)tructors
	// Array();
	Array(unsigned int n = 0);
	Array(const Array &copy);
	Array &operator = (const Array &assign);
	~Array();
	//Functions
	int	size() const;
	//Overloads
	T &operator[](unsigned int i);
	const T &operator[](unsigned int i) const;

};

#include "Array.tpp"

#endif