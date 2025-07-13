#pragma once
#include <iostream>
#include <string>
#include <algorithm>

template<typename T>
typename T::iterator	easyfind( T &container, int value );

class NotFoundException : public std::exception {
public:
	virtual const char* what() const throw() {
		return "No occurence was found!";
	}
};

#include "easyfind.tpp"