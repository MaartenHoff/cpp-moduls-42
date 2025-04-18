/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maahoff <maahoff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 15:00:50 by maahoff           #+#    #+#             */
/*   Updated: 2025/04/07 15:34:41 by maahoff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook 
{
	public:
		PhoneBook();
		void addContact();
		void displayContacts();
	
	private:
		Contact contacts[8];
		int num;
		int i;
};
