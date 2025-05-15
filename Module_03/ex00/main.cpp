#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("Bot1");
	ClapTrap b("Bot2");

	a.attack("Bot2");
	b.takeDamage(3);
	b.beRepaired(2);
	return 0;
}
