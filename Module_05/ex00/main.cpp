#include "Bureaucrat.hpp"

int main() {
	std::cout << "\n---constructor test---" << std::endl;
	try {
		Bureaucrat Bob("Bob", 42);
		std::cout << Bob << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n---too high grade test---" << std::endl;
	try {
		Bureaucrat tooHigh("TooHigh", 0);
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n---too low grade test---" << std::endl;
	try {
		Bureaucrat tooLow("TooLow", 200);
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n---too high grade test---" << std::endl;
	try {
		Bureaucrat boss("Boss", 1);
		boss.incrementGrade();
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n---too low grade test---" << std::endl;
	try {
		Bureaucrat intern("intern", 150);
		intern.decrementGrade();
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	
	return 0;
}
