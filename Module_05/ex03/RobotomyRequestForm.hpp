#pragma once
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string const	_target;
	
	public:
		RobotomyRequestForm( std::string const &target );
		RobotomyRequestForm( RobotomyRequestForm const &other );
		RobotomyRequestForm	&operator=( RobotomyRequestForm const &other );
		~RobotomyRequestForm();

		void execute(Bureaucrat const &executor) const;
};