#include "include/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon) {}

HumanA::~HumanA( void ) {}

void	HumanA::attack( void ) {
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}

void	HumanA::setName(std::string name) {
	_name = name;
}

std::string	HumanA::getName( void ) {
	return (_name);
}
