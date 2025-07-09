#pragma once
#include <iostream>
#include <string>
#include <exception>

template<typename T>
class Array
{
	private:
		T				*elements;
		unsigned int	n;
	
	public:
		Array();
		Array( unsigned int n );
		Array( Array const &other );
		Array	&operator = ( Array const &other );
		~Array();
		
		T		&operator [] ( int idx );
		const T	&operator[](int idx) const;

		unsigned int	size() const;
};

#include "Array.tpp"