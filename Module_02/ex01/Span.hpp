#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

class Span
{
	private:
		std::vector<int>	_nums;
		const unsigned int	_maxSize;
	
	public:
		Span( unsigned int N );
		Span( const Span &other );
		Span	&operator = ( const Span &other );
		~Span();

		void	addNumber( int num );
		int		shortestSpan();
		int		longestSpan();

		class AnException : public std::exception {
			private:
				std::string	_ex_msg;
			public:
				virtual ~AnException() throw() {}
				AnException(std::string const &ex_msg) : _ex_msg(ex_msg) {}
				virtual const char* what() const throw() {
					return _ex_msg.c_str();
				}
		};
};