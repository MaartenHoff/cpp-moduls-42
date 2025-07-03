#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++)
		_templates[i] = NULL;
	std::cout << "MateriaSource constructed" << std::endl;
}

MateriaSource::MateriaSource( const MateriaSource &other ){
	for (int i = 0; i < 4; i++)
	{
		if (other._templates[i] == NULL)
			_templates[i] = NULL;
		else
			_templates[i] = other._templates[i]->clone();
	}
	std::cout << "MateriaSource copied" << std::endl;
}

MateriaSource	&MateriaSource::operator=( const MateriaSource &other ) {
	if (this == &other)
		return (*this);
	for (int i = 0; i < 4; i++)
	{
		if (_templates[i])
			delete _templates[i];
		if (other._templates[i] == NULL)
			_templates[i] = NULL;
		else
			_templates[i] = other._templates[i]->clone();
	}
	std::cout << "* MateriaSource copied *" << std::endl;
	return (*this);
}
MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (_templates[i])
			delete _templates[i];
	}
	std::cout << "* MateriaSource destructed *" << std::endl;
}

void 		MateriaSource::learnMateria(AMateria *m) {
	for (int i = 0; i < 4; i++) {
		if (_templates[i] == NULL) {
			_templates[i] = m;
			std::cout << "* MateriaSource learned " << m->getType() << " *" << std::endl;
			return;
		}
	}
	std::cout << "* MateriaSource full, can't learn " << m->getType() << " *" << std::endl;
	delete m;
}

AMateria	*MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (_templates[i] && _templates[i]->getType() == type) {
			std::cout << "* MateriaSource creates " << type << " *" << std::endl;
			return _templates[i]->clone();
		}
	}
	std::cout << "* MateriaSource has no materia of type: " << type << " *" << std::endl;
	return NULL;
}