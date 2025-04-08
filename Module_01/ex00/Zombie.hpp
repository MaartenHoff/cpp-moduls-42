#pragma once
#include <iostream>
#include <string>

class	Zombie
{
	public:
		Zombie( std::string newName );
		~Zombie ();
		void	announce( void );
	private:
		std::string	name;
};

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );