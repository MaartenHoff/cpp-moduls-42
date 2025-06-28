#include"Dog.hpp"
#include"Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	std::cout << "=== ex00 Tests ===" << std::endl;
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
	C->makeSound();
	D->makeSound();
	A->makeSound();
	WC->makeSound();
	WA->makeSound();

	std::cout << "\n=== Copy & Assignment Tests ===" << std::endl;
	Cat originalCat;
	Cat copiedCat(originalCat);
	Cat assignedCat;
	assignedCat = originalCat;

	Dog originalDog;
	Dog copiedDog(originalDog);
	Dog assignedDog;
	assignedDog = originalDog;

	std::cout << "\n=== Destructors ex00 ===" << std::endl;
	delete A;
	delete D;
	delete C;
	delete WA;
	delete WC;

	std::cout << "\n=== ex01 Tests ===" << std::endl;
	const int n = 4;
	Animal* arr[n];
	for (int i = 0; i < n; ++i) {
		if (i < n/2)
			arr[i] = new Dog();
		else
			arr[i] = new Cat();
	}

	std::cout << "\n=== Deleting array ===" << std::endl;
	for (int i = 0; i < n; ++i)
		delete arr[i];

	std::cout << "\n=== Deep Copy Brain Test ===" << std::endl;
	Dog dog1;
	dog1.getBrain()->setIdea(0, "Original dog idea");
	Dog dog2 = dog1;
	dog1.getBrain()->setIdea(0, "Modified dog idea");

	std::cout << "dog1 brain[0]: " << dog1.getBrain()->getIdea(0) << std::endl;
	std::cout << "dog2 brain[0]: " << dog2.getBrain()->getIdea(0) << std::endl;
	return 0;
}
