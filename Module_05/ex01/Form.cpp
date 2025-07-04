#include "Form.hpp"

Form::Form( std::string const name, int signGrade, int executeGrade ) 
	: _name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade) {
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();
	std::cout << _name << ", Form with signGrade: " << _signGrade 
		<< ", executeGrade: " << _executeGrade << " constructed" << std::endl;
}

Form::Form( const Form &other ) 
	: _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _executeGrade(other._executeGrade){
	if (other._signGrade < 1 || other._executeGrade < 1)
		throw GradeTooHighException();
	if (other._signGrade > 150 || other._executeGrade > 150)
		throw GradeTooLowException();
	std::cout << _name << ", Form with signGrade: " << _signGrade 
		<< ", executeGrade: " << _executeGrade << ", signed: " << _signed << " copy constructed" << std::endl;
}

Form	&Form::operator = ( const Form &other ) {
	if (this != &other) {
		if (other._signGrade < 1 || other._executeGrade < 1)
			throw GradeTooHighException();
		if (other._signGrade > 150 || other._executeGrade > 150)
			throw GradeTooLowException();
		_signed = other._signed;
		_signGrade = other._signGrade;
		_executeGrade = other._executeGrade;
		std::cout << _name << ", Form with signGrade: " << _signGrade 
		<< ", executeGrade: " << _executeGrade << ", signed: " << _signed << " copied" << std::endl;
	}
	return (*this);
}

Form::~Form() {
	std::cout << _name << ", Form with signGrade: " << _signGrade 
		<< ", executeGrade: " << _executeGrade << ", signed: " << _signed << " destructed" << std::endl;
}

const std::string	Form::getName() const { return (_name); }
bool				Form::getSigned() const { return (_signed); }
int					Form::getSignGrade() const { return (_signGrade); }
int					Form::getExecuteGrade() const { return (_executeGrade); }

void	Form::beSigned( const Bureaucrat &B ) {
	if (B.getGrade() > _signGrade)
		throw (GradeTooLowException());
	_signed = true;
}

std::ostream	&operator << ( std::ostream &out, const Form &F ) {
	out << F.getName() << ", Form with signGrade: " << F.getSignGrade() 
		<< ", executeGrade: " << F.getExecuteGrade() << ", signed: " << F.getSigned() << ".";
	return (out);
}