#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain	*_brain;
public:
	Cat();
	Cat ( const Cat &other );
	Cat	&operator = ( const Cat &other );
	~Cat();

	Brain	*getBrain() const;
	void	makeSound() const ;
};