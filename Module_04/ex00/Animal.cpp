#include "Animal.hpp"

Animal::Animal() {
	type = "not specified";
	std::cout << "Animal constructed" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal destructed" << std::endl;
}

void	Animal::makeSound() {
	std::cout << "Animal sound" << std::endl;
}

std::string	Animal::getType(){
	std::cout << "getType called in " << type << std::endl;
	return type;
}