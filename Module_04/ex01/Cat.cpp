#include"Cat.hpp"

Cat::Cat() {
	type = "Cat";
	std::cout << "Cat constructed" << std::endl;
}

Cat::Cat( const Cat &other ) : Animal (other) {
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat	&Cat::operator=( const Cat &src ) {
	if (this != &src) {
		type = src.type;
	}
	std::cout << "Copy assignment operator called in " << type << std::endl;
	return (*this);
}

Cat::~Cat() {
	std::cout << "Cat destructed" << std::endl;
}

void	Cat::makeSound() const {
	std::cout << "Meow" << std::endl;
}
