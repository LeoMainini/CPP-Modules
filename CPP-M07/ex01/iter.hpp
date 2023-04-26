#ifndef ITER_H
#define ITER_H
#include <iostream>

template <typename T, size_t size> void iter(T (*array)[size], int len, void (*f)(T &)){
	for (int iter = 0; iter < len; iter++)
		f((*array)[iter]);
}

#endif