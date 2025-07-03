#include "Cure.hpp"

Cure::Cure() : AMateria( "Cure" ) {}

Cure::Cure( Cure const &other ) : AMateria(other) {}

Cure	&Cure::operator=(const Cure& other) {
	if (this != &other) {
		AMateria::operator=(other);
	}
	return *this;
}

Cure::~Cure() {
	std::cout << "Cure destructed" << std::endl;
}

Cure* Cure::clone() const {
	std::cout << "Cure got cloned" << std::endl;
	return new Cure(*this);
}

void	Cure::use( ICharacter& target ) {
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}