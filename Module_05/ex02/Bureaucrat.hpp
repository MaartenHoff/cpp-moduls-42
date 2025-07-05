#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class AForm;

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

		void	signForm( AForm &F );
		void 	executeForm(AForm const &F) const;

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