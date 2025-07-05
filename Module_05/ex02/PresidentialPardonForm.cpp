#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( std::string const &target ) 
	: AForm( "PresidentialPardonForm", 25, 5 ), _target(target) {
	std::cout << "PresidentialPardonForm with signGrade: 25, executeGrade: 5 constructed" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const &other )
	: AForm( "PresidentialPardonForm", 25, 5 ), _target(other._target) {
	std::cout << "PresidentialPardonForm with signGrade: 25, executeGrade: 5 copy constructed" << std::endl;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=( PresidentialPardonForm const &other ) {
	(void)other;
	std::cout << "PresidentialPardonForm with signGrade: 25, executeGrade: 5 copied" << std::endl;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm with signGrade: 25, executeGrade: 5 destructed" << std::endl;
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if (!getSigned())
		throw(FormNotSignedException());
	if (getExecuteGrade() < executor.getGrade())
		throw(GradeTooLowException());
	
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}