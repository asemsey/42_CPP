#include "include/DiamondTrap.hpp"
#include <iostream>

void	DiamondTrap::whoAmI( void ) {
	std::cout << "DiamondTrap: 'My name is " << _name << " and my ClapTrap name is "
			<< ClapTrap::_name << ".'\n";
}

// ------------------------------------------------------------------------------------------

DiamondTrap::DiamondTrap( void ) : ClapTrap(), ScavTrap(), FragTrap() {
	_name = ClapTrap::_name;
	ClapTrap::_name = _name + "_clap_name";
	_energy = ScavTrap::_energy;
	_damage = FragTrap::_damage;
	_hitpoints = FragTrap::_hitpoints;
	std::cout << "\x1B[2m[DiamondTrap default constructor called] (" << _name << ")\x1B[22m\n";
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) {
	_name = name;
	_energy = ScavTrap::_energy;
	_damage = FragTrap::_damage;
	_hitpoints = FragTrap::_hitpoints;
	std::cout << "\x1B[2m[DiamondTrap constructor called] (" << _name << ")\x1B[22m\n";
}

DiamondTrap::DiamondTrap( DiamondTrap& s ) : ClapTrap(s), ScavTrap(s), FragTrap(s) {
	std::cout << "\x1B[2m[DiamondTrap copy constructor called] (" << s._name << ")\x1B[22m\n";
	*this = s;
}

DiamondTrap&	DiamondTrap::operator=(DiamondTrap& s) {
	std::cout << "\x1B[2m[DiamondTrap copy assignment operator called] (" << _name << ")\x1B[22m\n";
	if (this != &s) {
		ScavTrap::operator=(s);
		FragTrap::operator=(s);
		_name = s._name;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap( void ) {
	std::cout << "\x1B[2m[DiamondTrap destructor called] (" << _name << ")\x1B[22m\n";
}
