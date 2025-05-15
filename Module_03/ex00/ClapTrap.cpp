#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) 
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {}
ClapTrap::ClapTrap( const ClapTrap &other ) { *this = other; }
ClapTrap	&ClapTrap::operator=( const ClapTrap &other )
{
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	return (*this);
}
ClapTrap::~ClapTrap() {}

void	ClapTrap::attack(const std::string& target)
{
	if (!_energyPoints || !_hitPoints)
	{
		std::cout << "ClapTrap " << _name << " can't attack\n";
		return ;
	}
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " attacks " << target
              << ", causing " << _attackDamage << " points of damage!\n";
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (!_energyPoints || !_hitPoints)
	{
		std::cout << "No energy- or hit points left\n";
		return ;
	}
	if (_hitPoints < amount)
        _hitPoints = 0;
	else
		_hitPoints -= amount;
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " takes " << amount << " damage!\n";
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!_energyPoints || !_hitPoints)
	{
		std::cout << "ClapTrap " << _name << " can't repair\n";
		return ;
	}
	_hitPoints += amount;
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " repairs itself for " << amount << " HP\n";
}
