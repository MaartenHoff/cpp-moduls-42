#include"Dog.hpp"

Dog::Dog() {
	type = "Dog";
	std::cout << "Dog constructed" << std::endl;
}

Dog::Dog( const Dog &other ) : Animal (other) {
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog	&Dog::operator=( const Dog &src ) {
	if (this != &src) {
		type = src.type;
	}
	std::cout << "Copy assignment operator called in " << type << std::endl;
	return (*this);
}

Dog::~Dog() {
	std::cout << "Dog destructed" << std::endl;
}

void	Dog::makeSound() const {
	std::cout << "Woof" << std::endl;
}