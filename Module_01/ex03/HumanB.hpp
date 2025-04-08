#pragma once
#include "Weapon.hpp"

class	HumanB
{
	public:
		std::string	name;
		Weapon		club;
		HumanB( std::string	name );
		void		attack();
		void		setWeapon(Weapon club);
};