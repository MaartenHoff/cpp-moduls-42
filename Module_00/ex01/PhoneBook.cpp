#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	num = 0;
	i = 0;
}

void PhoneBook::addContact() 
{
	Contact newContact;

	newContact.insertInfo();
	if (i >= 8)
		i = 0;
	contacts[i] = newContact;
	if (num < 8)
		num++;
	i++;
	std::cout << "Contact added!\n";
}

void PhoneBook::displayContacts() 
{
	int	j;
	std::string	output;

	j = 0;
	if (num == 0)
	{
		std::cout << "no Contacts yet\n";
		return ;
	}
	while (j < num)
	{
		std::cout << "|" << std::setw(10) << j << "|";
		if (contacts[j].firstName.length() > 10)
			output = contacts[j].firstName.substr(0, 9) + ".";
		else
			output = contacts[j].firstName;
		std::cout << std::setw(10) << output << "|";
		if (contacts[j].lastName.length() > 10)
			output = contacts[j].lastName.substr(0, 9) + ".";
		else
			output = contacts[j].lastName;
		std::cout << std::setw(10) << output << "|\n";
		j++;
	}
	std::cout << "Enter index of contact: ";
	while (!(std::cin >> j) || j < 0 || j >= num)
	{
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << "Invalid index!\n";
		std::cout << "Enter index of contact: ";
	}
	std::cout << "First name: \t" << contacts[j].firstName << "\n";
	std::cout << "Last name: \t" << contacts[j].lastName << "\n";
	std::cout << "Nickname: \t" << contacts[j].nickname << "\n";
	std::cout << "Phone number: \t" << contacts[j].number << "\n";
	std::cout << "Darkest secret:\t" << contacts[j].secret << "\n";
}
