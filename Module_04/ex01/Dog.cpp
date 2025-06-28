#include"Dog.hpp"

Dog::Dog() {
	type = "Dog";
	_brain = new Brain();
	std::cout << "Dog constructed" << std::endl;
}

Dog::Dog( const Dog &other ) : Animal (other) {
	_brain = new Brain(*other._brain);
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog	&Dog::operator=( const Dog &src ) {
	if (this != &src) {
		type = src.type;
		if (_brain)
			delete _brain;
		_brain = new Brain(*src._brain);
	}
	std::cout << "Copy assignment operator called in " << type << std::endl;
	return (*this);
}

Dog::~Dog() {
	delete _brain;
	std::cout << "Dog destructed" << std::endl;
}

Brain* Dog::getBrain() const {
    return _brain;
}

void	Dog::makeSound() const {
	std::cout << "Woof" << std::endl;
}