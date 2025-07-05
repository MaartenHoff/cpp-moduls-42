#pragma once
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string const	_target;
	
	public:
		ShrubberyCreationForm( std::string const &target );
		ShrubberyCreationForm( ShrubberyCreationForm const &other );
		ShrubberyCreationForm	&operator=( ShrubberyCreationForm const &other );
		~ShrubberyCreationForm();

		void execute(Bureaucrat const &executor) const;
};