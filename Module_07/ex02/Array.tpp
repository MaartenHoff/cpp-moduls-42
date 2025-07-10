#include "Array.hpp"

template<typename T>
Array<T>::Array() : elements(NULL), n(0) {}

template<typename T>
Array<T>::Array( unsigned int n ) : n(n) {
	elements = new T[n];
}

template<typename T>
Array<T>::Array( Array const &other ) : n(other.n) {
	elements = new T[other.n];
	for (unsigned int i = 0; i < n; i++) {
		elements[i] = other.elements[i];
	}
}

template<typename T>
Array<T>	&Array<T>::operator = ( Array const &other ) {
	if (this != &other){
		delete[] elements;
		elements = new T[other.n];
		n = other.n;
		for (unsigned int i = 0; i < n; i++) {
			elements[i] = other.elements[i];
		}
	}
	return (*this);
}

template<typename T>
Array<T>::~Array() {
	delete [] elements;
}

template<typename T>
T		&Array<T>::operator [] ( int idx ) {
	if (idx < 0 || static_cast<unsigned int>(idx) >= n)
		throw std::out_of_range("Index out of bounds");
	return elements[idx];
}

template<typename T>
const T	&Array<T>::operator[](int idx) const {
	if (idx < 0 || static_cast<unsigned int>(idx) >= n)
		throw std::out_of_range("Index out of bounds");
	return elements[idx];
}

template<typename T>
unsigned int	Array<T>::size() const {
	return n;
}