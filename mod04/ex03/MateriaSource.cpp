#include "include/MateriaSource.hpp"
#include <iostream>

// add a Materia to the list
void	MateriaSource::learnMateria(AMateria* m) {
	if (m == NULL || _amount == 4)
		return;
	_known[_amount] = m->clone();
	_amount++;
	delete m;
}

// return a copy of a known Materia
AMateria*	MateriaSource::createMateria(std::string const& type) {
	for (int i = 0; i < _amount; i++) {
		if (_known[i]->getType() == type)
			return (_known[i]->clone());
	}
	std::cout << "\x1B[2m[Could not create Materia of type " << type << "]\x1B[22m\n";
	return (0);
}

// -----------------------------------------------------------------

MateriaSource::MateriaSource( void ) : _amount(0) {
	for (int i = 0; i < 4; i++) {
		_known[i] = NULL;
	}
}

MateriaSource::MateriaSource( const MateriaSource& c ) {*this = c;}

MateriaSource::~MateriaSource( void ) {
	for (int i = 0; i < _amount; i++) {
		delete _known[i];
	}
}

MateriaSource&	MateriaSource::operator=( const MateriaSource& c ) {
	for (int i = 0; i < 4; i++) {
		delete _known[i];
		if (i < c._amount)
			_known[i] = c._known[i]->clone();
	}
	_amount = c._amount;
	return (*this);
}
