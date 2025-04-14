#pragma once
#include "Weapon.hpp"

class	HumanA
{
	private:
		std::string	name;
		Weapon		&club;

	public:
		HumanA( std::string	name, Weapon &club );

		void		attack();

};