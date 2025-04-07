/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maahoff <maahoff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:58:18 by maahoff           #+#    #+#             */
/*   Updated: 2025/04/07 15:35:19 by maahoff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

class Contact
{
	public:
		void	insertInfo();
		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string	number;
		std::string	secret;
};