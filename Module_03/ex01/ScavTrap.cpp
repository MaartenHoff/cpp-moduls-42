#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap without a name created\n";
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << _name << " created\n";
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << "ScavTrap copy constructor called for " << _name << "\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
        std::cout << "ScavTrap assignment operator called for " << _name << "\n";
    }
    return *this;
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