#include "AMateria.hpp"

AMateria::AMateria( std::string const & type ) : type(type) {
	std::cout << "Materia type: " << type << " constructed" << std::endl;
}

AMateria::AMateria( AMateria const &other ) : type(other.type) {
	std::cout << "Materia type: " << type << " copied" << std::endl;
}

AMateria &AMateria::operator=(AMateria const &other) {
	(void)other;
	return *this;
}

AMateria::~AMateria() {
	std::cout << "Materia type: " << type << " destructed" << std::endl;
}

std::string	const	&AMateria::getType() const {
	return (type);
}

void	AMateria::use( ICharacter& target ) {
	(void)target;
	std::cout << "* uses materia *" << std::endl;
}

