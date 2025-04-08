#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "Zombie created!\n";
}

Zombie::~Zombie()
{
	std::cout << name << " has been destroyed!\n";
}

void	Zombie::announce( int i )
{
	std::cout << name << " Nb: " << i + 1 << " says BraiiiiiiinnnzzzZ...\n";
}

void	Zombie::setName( std::string name)
{
	this->name = name;
	std::cout << "Zombie was named!\n";
}