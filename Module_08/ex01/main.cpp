#include "Span.hpp"
#include <ctime>

int	main( void )
{
	try {
		Span sp(10000);

		// filling up with random numbers
		std::srand(std::time(NULL));
		for (int i = 0; i < 10000; ++i) {
			sp.addNumber(std::rand());
		}

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;

		// to many numbers
		try {
			sp.addNumber(42);
		} 
		catch (const Span::AnException& e) {
			std::cout << "Expected exception: " << e.what() << std::endl;
		}

		// not enough numbers for Span functions
		Span smallSpan(1);
		try {
			smallSpan.shortestSpan();
		} 
		catch (const Span::AnException& e) {
			std::cout << "Expected exception: " << e.what() << std::endl;
		}

	} 
	catch (const std::exception& e) {
		std::cerr << "Unexpected error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}

// int main()
// {
// 	Span sp = Span(5);

// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);

// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;
// 	return 0;
// }