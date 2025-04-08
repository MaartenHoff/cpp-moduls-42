#include "HumanB.hpp"

HumanB::HumanB( std::string name ) : name(name), club("default") {}

void	HumanB::setWeapon(Weapon club)
{
	this->club = club;
}

void	HumanB::attack()
{
	std::cout << name << " attacks with their " << club.getType() << std::endl;
}