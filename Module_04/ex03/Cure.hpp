#pragma once
#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		Cure(Cure const &other);
		Cure	&operator=(const Cure& other);
		virtual ~Cure();

		virtual Cure	*clone() const;
		void	use( ICharacter& target );
};