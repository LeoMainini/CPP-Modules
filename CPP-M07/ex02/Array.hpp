#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>

template <class T>
class Array
{
private:
	T	*_items;
	int	_size;
public:
	//(Con/Des)tructors
	Array();
	Array(int n);
	Array(const Array &copy);
	Array &operator = (const Array &assign);
	~Array();
	//Functions
	int	size() const;
	//Overloads
	T &operator[](unsigned int i);
	const T &operator[](unsigned int i) const;

};

#endif