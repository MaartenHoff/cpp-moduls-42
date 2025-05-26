#include"Dog.hpp"
#include"Cat.hpp"

int main() {
	std::cout << "=== Constructor Tests ===" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "\n=== getType Tests ===" << std::endl;
	std::cout << "j type: " << j->getType() << std::endl;
	std::cout << "i type: " << i->getType() << std::endl;
	std::cout << "meta type: " << meta->getType() << std::endl;

	std::cout << "\n=== makeSound Tests ===" << std::endl;
	i->makeSound(); // should output Cat sound
	j->makeSound(); // should output Dog sound
	meta->makeSound(); // should output generic Animal sound

	std::cout << "\n=== Copy & Assignment Tests ===" << std::endl;
	Cat originalCat;
	Cat copiedCat(originalCat); // copy constructor
	Cat assignedCat;
	assignedCat = originalCat; // assignment operator

	Dog originalDog;
	Dog copiedDog(originalDog);
	Dog assignedDog;
	assignedDog = originalDog;

	std::cout << "\n=== Destructors ===" << std::endl;
	delete meta;
	delete j;
	delete i;

	return 0;
}