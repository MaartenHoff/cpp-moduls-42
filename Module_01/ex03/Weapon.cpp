#include "Weapon.hpp"

Weapon::Weapon( std::string type ) : type(type) {}

const std::string&	Weapon::getType()
{
	const std::string& ref = type;
	return (ref);
}

void	Weapon::setType( std::string type )
{
	this->type = type;
}