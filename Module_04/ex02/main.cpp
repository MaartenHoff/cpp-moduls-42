#include"Dog.hpp"
#include"Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	// Animal a;

	Cat Tom;
	std::cout << "Type: " << Tom.getType() << std::endl;
	Tom.makeSound();
	return 0;
}
