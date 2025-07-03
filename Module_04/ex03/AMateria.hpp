#pragma once
#include <string>
#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string	type;

	public:
		AMateria( std::string const & type );
		AMateria( AMateria const &other ) ;
		AMateria	&operator = ( AMateria const &other );
		~AMateria();

		std::string const & getType() const; // Returns the materia type

		virtual AMateria* clone() const = 0;
		virtual void use( ICharacter& target );
};