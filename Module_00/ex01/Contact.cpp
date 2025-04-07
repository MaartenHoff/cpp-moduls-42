/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maahoff <maahoff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:59:38 by maahoff           #+#    #+#             */
/*   Updated: 2025/04/07 14:59:49 by maahoff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::insertInfo() 
{
	std::cout << "first name:\t";
	std::cin >> firstName;
	std::cout << "last name:\t";
	std::cin >> lastName;
	std::cout << "nickname:\t";
	std::cin >> nickname;
	std::cout << "phone number:\t";
	std::cin >> number;
	std::cout << "darkest secret:\t";
	std::cin >> secret;
}