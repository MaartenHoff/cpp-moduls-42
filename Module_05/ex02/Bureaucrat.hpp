#pragma once
#include <iostream>
#include <string>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		std::string const	_name;
		int					_grade;

	public:
		Bureaucrat( std::string const &name, int grade );
		Bureaucrat( const Bureaucrat &other );
		Bureaucrat	&operator = ( const Bureaucrat &other );
		~Bureaucrat();

		const std::string	getName() const;
		int					getGrade() const;

		void	incrementGrade();
		void	decrementGrade();

		void	signForm( Form &F );
		void 	executeForm(AForm const & form);

		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw() {
					return ("Grade too high!");
				}
		};
		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw() {
					return ("Grade too low!");
				}
		};
};

std::ostream	&operator << (std::ostream& out, const Bureaucrat &B);