#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( std::string const &target ) 
	: AForm( "RobotomyRequestForm", 72, 45 ), _target(target) {
	std::cout << "RobotomyRequestForm with signGrade: 72, executeGrade: 45 constructed" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const &other )
	: AForm( "RobotomyRequestForm", 72, 45 ), _target(other._target) {
	std::cout << "RobotomyRequestForm with signGrade: 72, executeGrade: 45 copy constructed" << std::endl;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=( RobotomyRequestForm const &other ) {
	(void)other;
	std::cout << "RobotomyRequestForm with signGrade: 72, executeGrade: 45 copied" << std::endl;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm with signGrade: 72, executeGrade: 45 destructed" << std::endl;
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	if (!getSigned())
		throw(FormNotSignedException());
	if (getExecuteGrade() < executor.getGrade())
		throw(GradeTooLowException());
	
	std::cout << "Brrrr... drilling noises..." << std::endl;

	if (rand() % 2)
		std::cout << _target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "Robotomy failed on " << _target << "." << std::endl;
}