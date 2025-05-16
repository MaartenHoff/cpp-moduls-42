#include "ScavTrap.hpp"

int main() {
	ScavTrap scav("Guardian");

	scav.attack("Enemy");
	scav.takeDamage(30);
	scav.beRepaired(20);
	scav.guardGate();

	return 0;
}