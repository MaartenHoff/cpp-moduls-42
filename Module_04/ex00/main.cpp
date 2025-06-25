#include"Dog.hpp"
#include"Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	std::cout << "=== Constructor Tests ===" << std::endl;
	const Animal* A = new Animal();
	const Animal* D = new Dog();
	const Animal* C = new Cat();
	const WrongAnimal* WA = new WrongAnimal();
	const WrongAnimal* WC = new WrongCat();

	std::cout << "\n=== getType Tests ===" << std::endl;
	std::cout << "D type: " << D->getType() << std::endl;
	std::cout << "C type: " << C->getType() << std::endl;
	std::cout << "A type: " << A->getType() << std::endl;
	std::cout << "WA type: " << WA->getType() << std::endl;
	std::cout << "WC type: " << WC->getType() << std::endl;

	std::cout << "\n=== makeSound Tests ===" << std::endl;
	C->makeSound(); // should output Cat sound
	D->makeSound(); // should output Dog sound
	A->makeSound(); // should output generic Animal sound
	WC->makeSound(); // ruft WrongAnimal::makeSound(), da kein virtual
	WA->makeSound(); // ruft WrongAnimal::makeSound()

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
	delete A;
	delete D;
	delete C;
	delete WA;
	delete WC;

	return 0;
}
