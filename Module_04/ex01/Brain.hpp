#pragma once
#include "Cat.hpp"
#include "Dog.hpp"

class Brain
{
private:
	std::string	ideas[100];
public:
	Brain();
	Brain( const Brain &other );
	Brain	&operator = ( const Brain &other );
	~Brain();

	const std::string	&getIdea( int Number ) const;
	void				setIdea( int Number, const std::string &Idea );
};
