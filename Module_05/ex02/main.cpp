
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

int main() {
	std::srand(std::time(NULL));

	Bureaucrat alice("Alice", 50);
	Bureaucrat bob("Bob", 140);
	Bureaucrat carol("Carol", 3);

	// 0) execute without Sign
	{
		std::cout << "\n--- Test: execute without signing ---\n";
		ShrubberyCreationForm shrub("garden");
		try {
			shrub.execute(alice);
		}
		catch (const std::exception &e) {
			std::cerr << "Error executing ShrubberyCreationForm: " << e.what() << std::endl;
		}

		RobotomyRequestForm robo("Marvin");
		try {
			robo.execute(bob);
		}
		catch (const std::exception &e) {
			std::cerr << "Error executing RobotomyRequestForm: " << e.what() << std::endl;
		}

		PresidentialPardonForm pardon("Zaphod");
		try {
			pardon.execute(carol);
		}
		catch (const std::exception &e) {
			std::cerr << "Error executing PresidentialPardonForm: " << e.what() << std::endl;
		}
	}

	std::cout << std::endl;
	
	// 1) ShrubberyCreationForm
	{
		ShrubberyCreationForm shrub("home");
		std::cout << shrub << std::endl;
		alice.signForm(shrub);
		alice.executeForm(shrub);
	}

	std::cout << std::endl;

	// 2) RobotomyRequestForm
	{
		RobotomyRequestForm robo("Marvin");
		std::cout << robo << std::endl;
		bob.signForm(robo);
		bob.executeForm(robo);   // 50%
		bob.executeForm(robo);
	}

	std::cout << std::endl;

	// 3) PresidentialPardonForm
	{
		PresidentialPardonForm pardon("Zaphod");
		std::cout << pardon << std::endl;
		carol.signForm(pardon);
		carol.executeForm(pardon);
	}
	return 0;
}
