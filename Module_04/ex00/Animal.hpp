#pragma once
#include <iostream>
#include <string>

class Animal
{
protected:
	std::string type;
public:
	Animal();
	~Animal();

	void		makeSound();
	std::string	getType();
};
