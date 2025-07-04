#pragma once
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const	_name;
		bool				_signed;
		int					_signGrade;
		int					_executeGrade;
	
	public:
		Form( std::string const name, int signGrade, int executeGrade );
		Form( const Form &other );
		Form	&operator = ( const Form &other );
		~Form();

		const std::string	getName() const;
		bool				getSigned() const;
		int					getSignGrade() const;
		int					getExecuteGrade() const;

		void	beSigned( const Bureaucrat &B );

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

std::ostream	&operator << ( std::ostream &out, const Form &F );
