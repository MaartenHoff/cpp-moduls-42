#include "Animal.hpp"

Animal::Animal() {
	type = "Animal";
	std::cout << "Animal constructed" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal destructed" << std::endl;
}

Animal::Animal( const Animal &copy ) {
	*this = copy;
	std::cout << "Animal copied" << std::endl;
}

Animal	&Animal::operator=( const Animal &src ) {
	if (this != &src) {
		type = src.type;
	}
	std::cout << "Copy assignment operator called in " << type << std::endl;
	return (*this);
}

void	Animal::makeSound() const {
	std::cout << "Animal sound" << std::endl;
}

std::string	Animal::getType() const {
	std::cout << "getType called in " << type << std::endl;
	return type;
}