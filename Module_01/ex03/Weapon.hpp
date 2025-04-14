#pragma once
#include <iostream>
#include <string>

class Weapon
{
	private:
		std::string	type;

	public:
		Weapon( std::string type );

		const std::string&	getType();
		void				setType( std::string type );
};
