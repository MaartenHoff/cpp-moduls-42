#include"Dog.hpp"

Dog::Dog() {
	type = "Dog";
	std::cout << "Dog constructed" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog destructed" << std::endl;
}

void	Dog::makeSound() const {
	std::cout << "Woof" << std::endl;
}