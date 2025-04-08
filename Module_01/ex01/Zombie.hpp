#pragma once
#include <iostream>
#include <string>

class	Zombie
{
	public:
		Zombie();
		~Zombie ();
		void	announce( int i );
		void	setName( std::string name );
	private:
		std::string	name;
};

Zombie* zombieHorde( int N, std::string name );