#include "Array.hpp"

template <class T>
Array<T>::Array(): _size(0){
	_items = new T[_size]();
}

template <class T>
Array<T>::~Array(){
	delete _items;
}

template <class T>
Array<T>::Array(int n): _size(n){
	_items = new T[_size]();
}

template <class T>
Array<T>::Array(const Array<T> &copy) {
	*this = copy;
}

template <class T>
Array<T> &Array<T>::operator = (const Array<T>&assign)
{
	if (this != &assign)
	{
		delete this->_items;
		this->_items = new T[assign._size()]();
		_size = assign._size();
		for (int i = 0; i < size; i++)
			*this[i] = assign[i];
	}
	return *this;
}

template <class T>
int Array<T>::size() const {
	return (_size);
}

template <class T>
T &Array<T>::operator[](unsigned int i) { return (_items[i]); }

template <class T>
const T &Array<T>::operator[](unsigned int i) const { return (_items[i]); }
