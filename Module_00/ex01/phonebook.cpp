#include <iostream>
#include <string>
#include "PhoneBook.hpp"

int	main(void)
{
	std::string	input;
	PhoneBook	Book;
	Contact		Temp;

	while (1)
	{
		std::cout << "Enter either \"ADD\", \"SEARCH\" or \"EXIT\"\n";
		std::cin >> input;
		if (input == "EXIT")
			break ;
		else if (input == "ADD")
		{
			Temp.insert_info();
			Book.add_contact(Temp);
		}
		else if (input == "SEARCH")
			Book.display();
		std::cout << "\n";
	}
	return (0);	
}