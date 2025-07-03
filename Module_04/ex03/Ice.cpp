#include "Ice.hpp"

Ice::Ice() : AMateria( "Ice" ) {}

Ice::Ice( Ice const &other ) : AMateria(other) {}

Ice	&Ice::operator=(const Ice& other) {
	if (this != &other) {
		AMateria::operator=(other);
	}
	return *this;
}

Ice::~Ice() {
	std::cout << "Ice destructed" << std::endl;
}

Ice* Ice::clone() const {
	std::cout << "Ice got cloned" << std::endl;
	return new Ice(*this);
}

void	Ice::use( ICharacter& target ) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}