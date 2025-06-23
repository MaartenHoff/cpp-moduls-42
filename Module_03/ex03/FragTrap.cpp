#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Unnamed") {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " created\n";
}

FragTrap::FragTrap( std::string name ) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " created\n";
}

FragTrap::FragTrap ( const FragTrap &other ) : ClapTrap(other) {
	std::cout << "FragTrap copy constructor called for " << _name << "\n";
}

FragTrap	&FragTrap::operator = ( const FragTrap &other ) {
	if (this != &other) {
        ClapTrap::operator=(other);
        std::cout << "FragTrap assignment operator called for " << _name << "\n";
    }
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << _name << " destroyed\n";
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << _name << " wants a high five! ✋\n";
}