#pragma once
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string const	_name;
		bool				_signed;
		int					_signGrade;
		int					_executeGrade;
	
	public:
		AForm( std::string const name, int signGrade, int executeGrade );
		AForm( const AForm &other );
		AForm	&operator = ( const AForm &other );
		virtual ~AForm();

		const std::string	getName() const;
		bool				getSigned() const;
		int					getSignGrade() const;
		int					getExecuteGrade() const;

		void	beSigned( const Bureaucrat &B );
		virtual void 	execute( const Bureaucrat &executor ) const = 0;

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
		class FormNotSignedException : public std::exception {
			public:
				const char *what() const throw() {
					return "Form not signed!"; 
				}
		};
};

std::ostream	&operator << ( std::ostream &out, const AForm &F );
