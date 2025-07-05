
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main() {
	std::srand(std::time(NULL));

	Intern someIntern;
	AForm *formA = NULL;
	AForm *formB = NULL;
	AForm *formC = NULL;

	std::cout << "\n--- Test: valid form creation ---\n";
	try {
		formA = someIntern.makeForm("shrubbery creation", "home");
		std::cout << *formA << "\n" << std::endl;

		formB = someIntern.makeForm("robotomy request", "Marvin");
		std::cout << *formB << "\n" << std::endl;

		formC = someIntern.makeForm("presidential pardon", "Zaphod");
		std::cout << *formC << "\n" << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << "Failed to create form: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test: unknown form creation ---\n";
	try {
		AForm *bad = someIntern.makeForm("unknown form", "target");
		delete bad;
	}
	catch (const std::exception &e) {
		std::cerr << "Expected exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- destruction ---\n";
	delete formA;
	delete formB;
	delete formC;

	return 0;
}
