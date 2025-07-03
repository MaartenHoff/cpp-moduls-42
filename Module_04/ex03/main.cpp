#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
	std::cout << "--- subject tests ---" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	
	std::cout << "\n--- my tests ---" << std::endl;

	// unequip
	IMateriaSource* src2 = new MateriaSource();
	src2->learnMateria(new Ice());
	ICharacter* user = new Character("user");
	AMateria* lost = src2->createMateria("ice");
	user->equip(lost);
	user->unequip(0); // should not delete
	user->use(0, *user); // should do nothing
	delete lost;
	delete user;
	delete src2;

	std::cout << std::endl;

	// unknown type
	MateriaSource* s = new MateriaSource();
	s->learnMateria(new Ice());
	AMateria* unknown = s->createMateria("fire");
	if (!unknown)
		std::cout << "Unknown materia handled\n";
	delete s;

	std::cout << std::endl;

	// full inventory
	IMateriaSource* src3 = new MateriaSource();
	src3->learnMateria(new Cure());
	ICharacter* full = new Character("full");
	AMateria* overflow = NULL;
	for (int i = 0; i < 4; i++) {
		AMateria* m = src3->createMateria("cure");
		full->equip(m); // first 4 are fine
	}
	overflow = src3->createMateria("cure"); // 5th
	full->equip(overflow); // this won't equip
	delete overflow;
	delete full;
	delete src3;

	std::cout << std::endl;

	// deep copy
	IMateriaSource* src4 = new MateriaSource();
	src4->learnMateria(new Ice());
	Character original("original");
	AMateria* ice = src4->createMateria("ice");
	original.equip(ice);
	Character copy(original);
	original.unequip(0); // original has no materia now
	copy.use(0, original); // copy should still have it
	delete ice;
	delete src4;

	return 0;
}