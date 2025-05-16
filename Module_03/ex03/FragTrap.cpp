#include "FragTrap.hpp"

FragTrap::FragTrap( std::string name ) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " created\n";
}


FragTrap::~FragTrap() {
    std::cout << "FragTrap " << _name << " destroyed\n";
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << _name << " wants a high five! ✋\n";
}