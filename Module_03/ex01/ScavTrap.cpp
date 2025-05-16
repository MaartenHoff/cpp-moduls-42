#include "ScavTrap.hpp"

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap " << _name << " created\n";
}


ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << _name << " destroyed\n";
}

void	ScavTrap::attack( const std::string& target )
{
	if (!_energyPoints || !_hitPoints)
	{
		std::cout << "ScavTrap " << _name << " can't attack\n";
		return ;
	}
	_energyPoints--;
	std::cout << "ScavTrap " << _name << " attacks " << target
              << ", causing " << _attackDamage << " points of damage!\n";
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is now in Gatekeeper mode\n";
}