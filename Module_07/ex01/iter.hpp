#pragma once
#include <string>
#include <iostream>
#include <cstddef>

template<typename T>
void	printElement(T &element) {
	std::cout << element << std::endl;
}

template<typename T>
void	printConstElement(T const &element) {
	std::cout << element << std::endl;
}

template<typename T, size_t N>
void	iter(T (&array)[N], size_t length, void (*f)(T &element))
{
	for (size_t i = 0; i < length; i++) {
		f( array[i]);
	}
}
