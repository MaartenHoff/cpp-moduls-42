#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade) {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	std::cout << _name << ", bureaucrat with grade " << _grade << " constructed" << std::endl;
}

Bureaucrat::Bureaucrat( const Bureaucrat &other ) : _name(other._name), _grade(other._grade) {
	if (other._grade < 1)
		throw GradeTooHighException();
	if (other._grade > 150)
		throw GradeTooLowException();
	std::cout << _name << ", bureaucrat with grade " << _grade << " copy constructed" << std::endl;
}

Bureaucrat	&Bureaucrat::operator=( const Bureaucrat &other ) {
	if (this != &other) {
		if (other._grade < 1)
			throw (GradeTooHighException());
		if (other._grade > 150)
			throw (GradeTooLowException());
		_grade = other._grade;
		std::cout << _name << ", bureaucrat with grade " << _grade << " copied" << std::endl;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {
	std::cout << _name << ", bureaucrat with grade " << _grade << " destructed" << std::endl;
}

const std::string	Bureaucrat::getName() const {
	return(_name);
}

int	Bureaucrat::getGrade() const {
	return(_grade);
}

void	Bureaucrat::incrementGrade() {
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decrementGrade() {
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	_grade++;
}

void	Bureaucrat::signForm( Form &F ) {
	try {
		F.beSigned(*this);
		std::cout << _name << " signed " << F.getName() << std::endl;
	} 
	catch (const std::exception &e) {
		std::cout << _name << " couldn’t sign " << F.getName()
		          << " because " << e.what() << std::endl;
	}
}

std::ostream	&operator << (std::ostream& out, const Bureaucrat &B) {
	out << B.getName() << ", bureaucrat grade " << B.getGrade() << ".";
	return out;
}