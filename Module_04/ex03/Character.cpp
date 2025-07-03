#include "Character.hpp"

Character::Character( const std::string &name ) : name(name) {
	for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
	std::cout << "Character " << name << " constructed" << std::endl;
}

Character::Character( const Character &other ) : name(other.name) {
	for (int i = 0; i < 4; i++)
	{
		if (other.inventory[i] == NULL)
			inventory[i] = NULL;
		else
			inventory[i] = other.inventory[i]->clone();
	}
	std::cout << "Character " << name << " copied" << std::endl;
}

Character	&Character::operator=( const Character &other ) {
	if (this == &other)
		return *this;
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i])
			delete inventory[i];
		if (other.inventory[i] == NULL)
			inventory[i] = NULL;
		else
			inventory[i] = other.inventory[i]->clone();
	}
	std::cout << "Character " << name << " copied" << std::endl;
	return (*this);
}

Character::~Character() {
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i])
			delete inventory[i];
	}
	std::cout << "Character " << name << " destructed" << std::endl;
}

const std::string	&Character::getName() const {
	return (name);
}

void	Character::equip( AMateria *m ) {
	int	i = 0;

	while (i < 4 && inventory[i])
		i++;
	if (i < 4) {
		inventory[i] = m;
		std::cout << "* " << name << " equips " << m->getType() << " *" << std::endl;
	}
	else
		std::cout << "* no inventory space *" << std::endl;
}

void	Character::unequip(int idx) {
	if (idx >= 0 && idx < 4) {
		inventory[idx] = NULL;
		std::cout << "* " << name << " unequipped materia on pos: " << idx << " *" << std::endl;
	}
	else
		std::cout << "wrong idx" << std::endl;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0	|| idx > 3 || !inventory[idx])
		std::cout << "* " << name << " tries to use slot " << idx << ", but it is empty *" << std::endl;
	else
		inventory[idx]->use( target );
}