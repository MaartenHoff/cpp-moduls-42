#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
	std::cout << "\n--- ClapTrap Test ---\n";
	ClapTrap clap("Clappy");
	clap.attack("Target A");
	clap.takeDamage(5);
	clap.beRepaired(3);

	std::cout << "\n--- ScavTrap Test ---\n";
	ScavTrap scav("Scavy");
	scav.attack("Target B");
	scav.takeDamage(20);
	scav.beRepaired(10);
	scav.guardGate();

	std::cout << "\n--- FragTrap Test ---\n";
	FragTrap frag("Fraggy");
	frag.attack("Target C");
	frag.takeDamage(50);
	frag.beRepaired(25);
	frag.highFivesGuys();

	std::cout << "\n--- DiamondTrap Test ---" << std::endl;
	DiamondTrap diamy("Diamy");
	diamy.attack("Target D");
	diamy.takeDamage(40);
	diamy.beRepaired(20);
	diamy.whoAmI();
	std::cout << "\n--- Destruction Begins ---" << std::endl;

	std::cout << "\n--- Destruction Begins ---\n";
	return 0;
}