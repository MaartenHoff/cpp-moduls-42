#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain consructed" << std::endl;
}

Brain::Brain( const Brain &other) {
	std::copy(std::begin(other.ideas), std::end(other.ideas), std::begin(ideas));
	std::cout << "Brain copied" << std::endl;
}

Brain	&Brain::operator = (const Brain &other ) {
	if (this != &other) {
		std::copy(std::begin(other.ideas), std::end(other.ideas), std::begin(ideas));
	}
	std::cout << "Copy assignment operator in Brain" << std::endl;
	return (*this);
}

Brain::~Brain() {
	std::cout << "Brain destructed" << std::endl;
}

const std::string	&Brain::getIdea( int index ) const {
	return (ideas[index]);
}

void	Brain::setIdea( int index, const std::string &idea ) {
	ideas[index] = idea;
}