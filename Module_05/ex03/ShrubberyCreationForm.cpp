#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( std::string const &target ) 
	: AForm( "ShrubberyCreationForm", 145, 137 ), _target(target) {
	std::cout << "ShrubberyCreationForm with signGrade: 145, executeGrade: 137 constructed" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const &other )
	: AForm( "ShrubberyCreationForm", 145, 137 ), _target(other._target) {
	std::cout << "ShrubberyCreationForm with signGrade: 145, executeGrade: 137 copy constructed" << std::endl;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=( ShrubberyCreationForm const &other ) {
	(void)other;
	std::cout << "ShrubberyCreationForm with signGrade: 145, executeGrade: 137 copied" << std::endl;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm with signGrade: 145, executeGrade: 137 destructed" << std::endl;
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (!getSigned())
		throw(FormNotSignedException());
	if (getExecuteGrade() < executor.getGrade())
		throw(GradeTooLowException());
	
	std::ofstream out((_target + "_shrubbery").c_str());
	if (!out)
		throw std::runtime_error("Failed to open output file");

	out << "       _-_" << std::endl;
	out << "    /~~   ~~\\" << std::endl;
	out << " /~~         ~~\\" << std::endl;
	out << "{               }" << std::endl;
	out << " \\  _-     -_  /" << std::endl;
	out << "   ~  \\\\ //  ~" << std::endl;
	out << "_- -   | | _- _" << std::endl;
	out << "  _ -  | |   -_" << std::endl;
	out << "       | |" << std::endl;
	out << "      /   \\" << std::endl;
	out.close();
}