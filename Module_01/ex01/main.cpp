#include "Zombie.hpp"

int	main( void )
{
	Zombie *firstZombie;

	firstZombie = zombieHorde( 5, "gustav" );

	delete[] firstZombie;
	return (0);
}