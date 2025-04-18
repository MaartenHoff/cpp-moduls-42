#include "Harl.hpp"

void	Harl::debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special"
				<< "-ketchup burger. \nI really do!\n\n";
}

void	Harl::info( void )
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. \nYou didn’t put "
				<< "enough bacon in my burger! \nIf you did, I wouldn’t be asking for more!\n\n";
}

void	Harl::warning( void )
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. \nI’ve been coming for"
				<< "years, whereas you started working here just last month.\n\n";
}

void	Harl::error( void )
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now.\n\n";
}

static int  toLevelCode(const std::string &lvl) 
{
    if (lvl == "DEBUG")   return 0;
    if (lvl == "INFO")    return 1;
    if (lvl == "WARNING") return 2;
    if (lvl == "ERROR")   return 3;
    return -1;
}

void Harl::complain( std::string level )
{
	switch (toLevelCode(level)) 
	{
		case 0:
			debug();
		case 1:
			info();
		case 2:
			warning();
		case 3:
			error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
}