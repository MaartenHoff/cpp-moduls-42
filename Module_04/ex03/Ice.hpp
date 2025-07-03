#pragma once
#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		Ice(Ice const &other);
		Ice	&operator=(const Ice& other);
		virtual ~Ice();

		virtual Ice	*clone() const;
		void	use( ICharacter& target );
};