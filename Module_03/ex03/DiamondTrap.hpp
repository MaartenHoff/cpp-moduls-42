#pragma once
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap
{
private:
	std::string	_name;

public:
	DiamondTrap();
	DiamondTrap( std::string _name );
	DiamondTrap( const DiamondTrap &other );
	DiamondTrap	&operator = ( const DiamondTrap &other );
	~DiamondTrap();

	using ScavTrap::attack;
	void	whoAmI();
};