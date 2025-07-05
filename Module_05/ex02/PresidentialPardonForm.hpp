#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string const	_target;
	
	public:
		PresidentialPardonForm( std::string const &target );
		PresidentialPardonForm( PresidentialPardonForm const &other );
		PresidentialPardonForm	&operator=( PresidentialPardonForm const &other );
		~PresidentialPardonForm();

		void execute(Bureaucrat const &executor) const;
};