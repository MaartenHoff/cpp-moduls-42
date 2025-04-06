#include <iostream>
#include <string>

class Contact
{
	public:
		std::string	first;
		std::string	last;
		std::string	nickname;
		std::string	number;
		std::string	secret;

		void	insert_info()
		{
			std::cout << "Enter first name: ";
			std::cin >> first;
			std::cout << "Enter last name: ";
			std::cin >> last;
			std::cout << "Enter nickname: ";
			std::cin >> nickname;
			std::cout << "Enter phone number: ";
			std::cin >> number;
			std::cout << "Enter darkest secret: ";
			std::cin >> secret;
		}
			
};

class PhoneBook 
{
	public:
		int		num;
		int		del;
		Contact	contacts[8];
		PhoneBook()
		{
			num = 0;
			del = 0;
		}
		void	add_contact(Contact new_contact)
		{
			int	i;

			i = num;
			if (num >= 8)
				del++;
			contacts[i].first = new_contact.first;
			contacts[i].last = new_contact.last;
			contacts[i].nickname = new_contact.nickname;
			contacts[i].number = new_contact.number;
			contacts[i].secret = new_contact.secret;
			num++;
			std::cout << "Contact number " << num << " was added!\n";
		}
		void	display()
		{
			int	i;

			if (num == 0)
			{
				std::cout << "no Contacts yet\n";
				return ;
			}
			i = del;
			while (i < num)
			{
				std::cout << "Index: " << i - del << " | ";
				std::cout << "First Name: " + contacts[i].first + " | ";
				std::cout << "Last Name: " + contacts[i].last + "\n";
				i++;
			}
			std::cout << "Enter index of contact: ";
			std::cin >> i;
			while (i < 0 || i + del >= num)
			{
				std::cout << "Invalid index!\n";
				std::cout << "Enter index of contact: ";
				std::cin >> i;
			}
			i += del;
			std::cout << "First name: \t" << contacts[i].first << "\n";
			std::cout << "Last name: \t" << contacts[i].last << "\n";
			std::cout << "Nickname: \t" << contacts[i].nickname << "\n";
			std::cout << "Phone number: \t" << contacts[i].number << "\n";
			std::cout << "Darkest secret:\t" << contacts[i].secret << "\n";
		}
};

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