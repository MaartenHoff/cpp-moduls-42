#include "RPN.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Usage: ./RPN \"inverted Polish mathematical expression\"" << std::endl;
		return 1;
	}
	try {
		RPN calculator;
		calculator.calculate(argv[1]);
	} 
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
