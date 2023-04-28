#include <stdexcept>


// template <class T>
// Array<T>::Array(): _items(NULL), _size(0){ }

template <class T>
Array<T>::~Array(){
	delete[] _items;
}

template <class T>
Array<T>::Array(unsigned int n): _size((unsigned int)n){
	if (_size == 0)
		_items = NULL;
	else
		_items = new T[_size]();
}

template <class T>
Array<T>::Array(const Array<T> &copy) : _items(NULL), _size(0) {
	*this = copy;
}

template <class T>
Array<T> &Array<T>::operator= (const Array<T>&assign)
{
	if (this != &assign)
	{
		if (_items)
			delete[] _items;
		_items = new T[assign.size()]();
		_size = assign.size();
		for (unsigned int i = 0; i < _size; i++)
			(*this)[i] = assign[i];
	}
	return *this;
}

template <class T>
int Array<T>::size() const {
	return (_size);
}

template <class T>
T &Array<T>::operator[](unsigned int i) {
	if (i < 0 || i >= _size)
		throw (std::out_of_range("index out of bounds"));
	return (_items[i]); 	 
}

template <class T>
const T &Array<T>::operator[](unsigned int i) const {
	if (i < 0 || i >= _size)
		throw (std::out_of_range("index out of bounds"));
	return (_items[i]);
}