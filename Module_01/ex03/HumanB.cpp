#include "HumanB.hpp"

HumanB::HumanB( std::string name ) : name(name), club(NULL) {}

void	HumanB::setWeapon(Weapon &weapon)
{
	club = &weapon;
}

void	HumanB::attack()
{
	if (!club)
		std::cout << name << " attacks with their hands" << std::endl;
	else
		std::cout << name << " attacks with their " << (*club).getType() << std::endl;
}