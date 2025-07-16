#include "RPN.hpp"

RPN::RPN() {}
RPN::RPN( const RPN &other ) : _stack(other._stack) {}
RPN	&RPN::operator = ( const RPN &other ) {if (this != &other) _stack = other._stack; return *this;}
RPN::~RPN() {}

void	RPN::calculate( const std::string &input ) {
	
}