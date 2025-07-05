#include "Intern.hpp"

Intern::Intern() {
	std::cout << "Intern constructed" << std::endl;
}

Intern::Intern( Intern const &other ) {
	(void)other;
	std::cout << "Intern copy constructed" << std::endl;
}

Intern	&Intern::operator = ( Intern const &other) {
	(void)other;
	std::cout << "Intern copied" << std::endl;
	return (*this);
}

Intern::~Intern() {
	std::cout << "Intern destructed" << std::endl;
}

static int  toFormCode(const std::string &name) 
{
	if (name == "shrubbery creation")	return 0;
	if (name == "robotomy request")		return 1;
	if (name == "presidential pardon")	return 2;
	return -1;
}

AForm	*Intern::makeForm( std::string const &name, std::string const &target ) const {
	AForm	*F = NULL;
	switch (toFormCode(name)) 
	{
		case 0:
			F = new ShrubberyCreationForm(target);
			break;
		case 1:
			F = new RobotomyRequestForm(target);
			break;
		case 2:
			F = new PresidentialPardonForm(target);
			break;
		default:
			throw(UnknownFormException());
	}
	std::cout << "Intern creates " << name << std::endl;
	return (F);
}