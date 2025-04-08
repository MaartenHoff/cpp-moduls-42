#include "Zombie.hpp"

Zombie::Zombie( std::string name ) : name(name)
{
	std::cout << name << " has been created.\n";
}

Zombie::~Zombie()
{
	std::cout << name << " has been destroyed!\n";
}

void	Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}