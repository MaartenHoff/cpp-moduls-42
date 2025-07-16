#pragma once
#include <iostream>
#include <string>
#include <stack>

class RPN
{
	private:
		std::stack<int>	_stack;

	public:
		RPN();
		RPN( const RPN &other );
		RPN	&operator = ( const RPN &other );
		~RPN();

		void	calculate( const std::string &input );
};