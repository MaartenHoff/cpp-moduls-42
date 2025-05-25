#pragma once
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap
{
private:
	std::string	_name;

public:
	DiamondTrap( std::string _name );
	~DiamondTrap();

	using ScavTrap::attack;
	void	whoAmI();
};