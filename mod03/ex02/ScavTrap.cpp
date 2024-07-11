#include "include/ScavTrap.hpp"
#include <iostream>

void	ScavTrap::attack(const std::string& target) {
	if (_energy && _hitpoints) {
		_energy--;
		std::cout << "ScavTrap " << _name << " attacks! " << target << " suffers \033[31m"
				<< _damage << "\033[0m point(s) of damage.\n";
	}
	else if (!_energy) {
		std::cout << "ScavTrap " << _name << " is too tired to attack!\n";
	}
	else
		std::cout << "ScavTrap " << _name << " does not have enough hit points to attack!\n";
}

void ScavTrap::guardGate() {
	if (!_guard) {
		std::cout << "ScavTrap " << _name << " is now in Gate keeper mode.\n";
		_guard = true;
	}
	else
		std::cout << "ScavTrap " << _name << " is already in Gate keeper mode.\n";
}

// ------------------------------------------------------------------------------------------

ScavTrap::ScavTrap( void ) {
	std::cout << "\x1B[2m[ScavTrap Default constructor called] (" << _name << ")\x1B[22m\n";
	_energy = 50;
	_damage = 20;
	_hitpoints = 100;
	_guard = false;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
	std::cout << "\x1B[2m[ScavTrap Constructor called] (" << _name << ")\x1B[22m\n";
	_energy = 50;
	_damage = 20;
	_hitpoints = 100;
	_guard = false;
}

ScavTrap::ScavTrap( ScavTrap& s ) : ClapTrap(s) {
	std::cout << "\x1B[2m[ScavTrap Copy constructor called] (" << _name << ")\x1B[22m\n";
	*this = s;
}

ScavTrap&	ScavTrap::operator=(ScavTrap& s) {
	std::cout << "\x1B[2m[ScavTrap Copy assignment operator called] (" << _name << ")\x1B[22m\n";
	if (this != &s) {
		ClapTrap::operator=(s);
	}
	return (*this);
}

ScavTrap::~ScavTrap( void ) {
	std::cout << "\x1B[2m[ScavTrap Destructor called] (" << _name << ")\x1B[22m\n";
}
