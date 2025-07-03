#include "Brain.hpp"

Brain::Brain() {
	for (int i = 0; i < 100; ++i)
		ideas[i].clear();
	std::cout << "Brain consructed" << std::endl;
}

Brain::Brain( const Brain &other) {
	std::copy(other.ideas, other.ideas + 100, ideas);
	std::cout << "Brain copied" << std::endl;
}

Brain	&Brain::operator = (const Brain &other ) {
	if (this != &other) {
		std::copy(other.ideas, other.ideas + 100, ideas);
	}
	std::cout << "Copy assignment operator in Brain" << std::endl;
	return (*this);
}

Brain::~Brain() {
	std::cout << "Brain destructed" << std::endl;
}

const std::string	&Brain::getIdea( int index ) const {
	if (index >= 0 && index < 100)
		return ideas[index];
	static const std::string empty = "";
	return empty;
}

void	Brain::setIdea( int index, const std::string &idea ) {
	if (index >= 0 && index < 100)
		ideas[index] = idea;
}