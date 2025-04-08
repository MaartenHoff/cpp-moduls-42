#pragma once
#include "Weapon.hpp"

class	HumanA
{
	public:
		std::string	name;
		Weapon		club;
		void		attack();
		HumanA( std::string	name, Weapon club );
};