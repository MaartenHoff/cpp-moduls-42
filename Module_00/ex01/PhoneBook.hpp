/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maahoff <maahoff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 15:00:50 by maahoff           #+#    #+#             */
/*   Updated: 2025/04/06 15:01:16 by maahoff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>

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
			std::cout << "first name:\t";
			std::cin >> first;
			std::cout << "last name:\t";
			std::cin >> last;
			std::cout << "nickname:\t";
			std::cin >> nickname;
			std::cout << "phone number:\t";
			std::cin >> number;
			std::cout << "darkest secret:\t";
			std::cin >> secret;
		}	
};

class PhoneBook 
{
	public:
		int		num;
		int		i;
		Contact	contacts[8];
		PhoneBook()
		{
			num = 0;
			i = 0;
		}
		void	add_contact(Contact new_contact)
		{
			if (i >= 8)
				i = 0;
			contacts[i].first = new_contact.first;
			contacts[i].last = new_contact.last;
			contacts[i].nickname = new_contact.nickname;
			contacts[i].number = new_contact.number;
			contacts[i].secret = new_contact.secret;
			if (num < 8)
				num++;
			i++;
			std::cout << "Contact number " << num << " was added!\n";
		}
		void	display()
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
				if (contacts[j].first.length() > 10)
					output = contacts[j].first.substr(0, 9) + ".";
				else
					output = contacts[j].first;
				std::cout << std::setw(10) << output << "|";
				if (contacts[j].last.length() > 10)
					output = contacts[j].last.substr(0, 9) + ".";
				else
					output = contacts[j].last;
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
			std::cout << "First name: \t" << contacts[j].first << "\n";
			std::cout << "Last name: \t" << contacts[j].last << "\n";
			std::cout << "Nickname: \t" << contacts[j].nickname << "\n";
			std::cout << "Phone number: \t" << contacts[j].number << "\n";
			std::cout << "Darkest secret:\t" << contacts[j].secret << "\n";
		}
};
