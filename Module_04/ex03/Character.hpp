#pragma once
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		const std::string	name;
		AMateria* 			inventory[4];
	public:
		Character( const std::string &name );
		Character( const Character &other );
		Character	&operator = ( const Character &other );
		virtual ~Character();
		
		std::string const &getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};