#pragma once
#include <iostream>
#include <string>

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