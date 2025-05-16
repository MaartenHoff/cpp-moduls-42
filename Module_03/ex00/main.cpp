#include "ClapTrap.hpp"

int main() {
	std::cout << "\n--- ClapTrap Test ---\n";
	ClapTrap clap("Clappy");
	clap.attack("Target A");
	clap.takeDamage(5);
	clap.beRepaired(3);

	std::cout << "\n--- Destruction Begins ---\n";
	return 0;
}