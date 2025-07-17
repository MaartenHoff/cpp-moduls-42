#include "RPN.hpp"

RPN::RPN() {}
RPN::RPN( const RPN &other ) : _stack(other._stack) {}
RPN	&RPN::operator = ( const RPN &other ) {if (this != &other) _stack = other._stack; return *this;}
RPN::~RPN() {}

bool isOperation(char c) {
	return (c == '+' || c == '-' || c == '/' || c == '*');
}

int	doOperation( char operatation, int a, int b) {
	if ( operatation == '+')
		return (a + b);
	else if ( operatation == '-')
		return (b - a);
	else if ( operatation == '/') {
		if (a == 0) throw std::invalid_argument("Error: Can not devide by 0.");
		return (b / a);
	}
	else
		return (a * b);
}

void	RPN::calculate( const std::string &input ) {
	for( size_t i = 0; input[i] || (i > 1 && input[i - 1]); i += 2) {
		if (isdigit(input[i]))
			_stack.push(static_cast<int>(input[i]) - 48);
		if (isOperation(input[i])) {
			if (_stack.size() < 2)
				throw std::invalid_argument("Error: function is not valid!");
			int	a = _stack.top();
			_stack.pop();
			int	b = _stack.top();
			_stack.pop();
			try { 
				_stack.push(doOperation(input[i], a, b));
			} catch (...) { 
				std::cerr << "Error: Can not devide by 0." << std::endl;
				return ;
			}
		}
	}
	if (_stack.size() != 1)
		throw std::invalid_argument("Error: function is not valid!");
	std::cout << _stack.top() << std::endl;
}