#include "PhoneBook.hpp"

int	main(void)
{
	std::string	input;
	PhoneBook	Book;

	while (1)
	{
		std::cout << "Enter either \"ADD\", \"SEARCH\" or \"EXIT\"\n";
		std::cin >> input;

		if (input == "EXIT")
			break ;
		else if (input == "ADD")
			Book.addContact();
		else if (input == "SEARCH")
			Book.displayContacts();

		std::cout << "\n";
	}
	return (0);	
}