#include"Cat.hpp"

Cat::Cat() {
	type = "Cat";
	_brain = new Brain();
	std::cout << "Cat constructed" << std::endl;
}

Cat::Cat( const Cat &other ) : Animal (other) {
	_brain = new Brain(*other._brain);
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat	&Cat::operator=( const Cat &src ) {
	if (this != &src) {
		type = src.type;
		if (_brain)
			delete _brain;
		_brain = new Brain(*src._brain);
	}
	std::cout << "Copy assignment operator called in " << type << std::endl;
	return (*this);
}

Cat::~Cat() {
	delete _brain;
	std::cout << "Cat destructed" << std::endl;
}

Brain* Cat::getBrain() const {
    return _brain;
}

void	Cat::makeSound() const {
	std::cout << "Meow" << std::endl;
}
