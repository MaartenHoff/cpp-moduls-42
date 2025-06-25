#include "WrongCat.hpp"

WrongCat::WrongCat() {
	type = "WrongCat";
	std::cout << "WrongCat constructed" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
	if (this != &other) {
		type = other.type;
	}
	std::cout << "Copy assignment operator called in " << type << std::endl;
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructed" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "Meow" << std::endl;
}
