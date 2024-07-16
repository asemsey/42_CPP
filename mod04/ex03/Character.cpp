#include "include/Character.hpp"
#include <iostream>

void	Character::showPockets() {
	for (int i = 0; i < 4; i++) {
		std::cout << i << "\t|\t";
		if (i < _amount)
			std::cout << _inventory[i]->getType();
		else if (_inventory[i])
			std::cout << "(" << _inventory[i]->getType() << ")";
		std::cout << std::endl;
	}
}

void	Character::equip(AMateria* m) {
	if (m == NULL || _amount == 4) {
		if (_amount == 4)
			std::cout << _name << "'s inventory is full!\n";
		delete m;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (_inventory[i] == m) {
			std::cout << "\x1B[2m[" << _name << " already equipped this Materia]\x1B[22m\n";
			return ;
		}
	}
	std::cout << "\x1B[2m[" << _name << " equipped "<< m->getType() << "]\x1B[22m\n";
	if (_inventory[_amount])
		delete _inventory[_amount];
	_inventory[_amount] = m;
	_amount++;
}

void	Character::unequip(int idx) {
	if (idx < 0 || idx >= _amount) {
		std::cout << "\x1B[2m[Index " << idx << " out of range]\x1B[22m\n";
		return ;
	}
	std::cout << "\x1B[2m[" << _name << " unequipped "<< _inventory[idx]->getType() << "]\x1B[22m\n";
	for (int i = idx + 1; i < _amount - 1; i++)
		*_inventory[i - 1] = *_inventory[i];
	_amount--;//ignore anything after instead of deleting
}

void	Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx >= _amount) {
		std::cout << "\x1B[2m[Index " << idx << " out of range]\x1B[22m\n";
		return ;
	}
	_inventory[idx]->use(target);
}

std::string const&	Character::getName() const {return _name;}

// -----------------------------------------------------------------

Character::Character( void ) : _name("Chara"), _amount(0) {
	for (int i = 0; i < 4; i++) {
		_inventory[i] = NULL;
	}
}

Character::Character( std::string name ) : _name(name), _amount(0) {
	for (int i = 0; i < 4; i++) {
		_inventory[i] = NULL;
	}
}

Character::Character( Character& c ) {*this = c;}

Character& Character::operator=( Character& c ) {
	for (int i = 0; i < _amount; i++)
		delete _inventory[i];
	for (int i = 0; i < c._amount; i++)
		_inventory[i] = c._inventory[i]->clone();
	_name = c._name;
	_amount = c._amount;
	return (*this);
}

Character::~Character( void ) {
	for (int i = 0; i < 4; i++) {
		if (_inventory[i])
			delete _inventory[i];
	}
}
