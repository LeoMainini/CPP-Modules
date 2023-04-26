template <typename T>
T max(T x, T y){
	return ((x > y) ? x : y);
}

template <typename T>
T min(T x, T y){
	return ((x > y) ? y : x);
}

template <typename T> void swap(T &a, T &b){
	T temp = a;
	a = b;
	b = temp;
}