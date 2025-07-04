#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	std::cout << "\n--- Form signing test ---" << std::endl;
	try {
		Bureaucrat Ben("Ben", 50);
		Form formA("FormA", 45, 100);

		std::cout << formA << std::endl;
		Ben.signForm(formA);
		std::cout << formA << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n--- Insufficient grade to sign ---" << std::endl;

	try {
		Bureaucrat bob("Bob", 100);
		Form formB("FormB", 50, 100);

		bob.signForm(formB);
		std::cout << formB << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n--- Invalid Form creation ---" << std::endl;

	try {
		Form invalidForm("Invalid", 0, 10);
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}
