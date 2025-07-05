#pragma once
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern();
		Intern( Intern const &other );
		Intern	&operator = ( Intern const &other);
		~Intern();

		AForm	*makeForm( std::string const &name, std::string const &target ) const;

		class UnknownFormException : public std::exception {
			public:
				const char *what() const throw() {
					return "Intern cannot create this form: unknown form name";
				}
		};
};