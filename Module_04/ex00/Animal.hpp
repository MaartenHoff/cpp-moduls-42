#pragma once
#include <iostream>
#include <string>

class Animal
{
protected:
	std::string type;
public:
	Animal();
	virtual ~Animal();
	Animal( const Animal &copy );
	Animal	&operator=( const Animal &src );

	virtual void	makeSound() const ;
	std::string		getType() const ;
};
