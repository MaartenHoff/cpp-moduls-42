#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() 
	: ClapTrap("unnamed_clap_name"), FragTrap("unnamed"), ScavTrap("unnamed"), _name("unnamed")
{
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap unnamed constructed\n";
}

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name)
{
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap " << _name << " constructed\n";
}

DiamondTrap::DiamondTrap( const DiamondTrap &other ) 
	: ClapTrap(other), FragTrap(other), ScavTrap(other), _name(other._name) {
	std::cout << "DiamondTrap copy constructor called for " << _name << "\n";
}

DiamondTrap	&DiamondTrap::operator=( const DiamondTrap & other ) {
	if (this != &other) {
		ClapTrap::operator=(other);
		_name = other._name;
		std::cout << "DiamondTrap assignment operator called for " << _name << "\n";
	}
	return (*this);
	
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << _name << " destructed\n";
}

void	DiamondTrap::whoAmI()
{
	std::cout << "My name is " << _name << ", ClapTrap name is " << ClapTrap::_name << "\n";
}
