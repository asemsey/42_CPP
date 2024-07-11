#include "include/FragTrap.hpp"
#include <iostream>

void FragTrap::highFivesGuys( void ) {
	std::cout << "FragTrap " << this->_name
			<< ": 'High five! 🖐️ \x1B[3m *thunderous clap*\x1B[23m Let's gooooooooooo!'\n";
}

// ------------------------------------------------------------------------------------------

FragTrap::FragTrap( void ) {
	std::cout << "\x1B[2m[FragTrap default constructor called] (" << _name << ")\x1B[22m\n";
	_energy = 100;
	_damage = 30;
	_hitpoints = 100;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	std::cout << "\x1B[2m[FragTrap constructor called] (" << name << ")\x1B[22m\n";
	_energy = 100;
	_damage = 30;
	_hitpoints = 100;
}

FragTrap::FragTrap( FragTrap& s ) : ClapTrap(s) {
	std::cout << "\x1B[2m[FragTrap copy constructor called] (" << s._name << ")\x1B[22m\n";
	*this = s;
}

FragTrap&	FragTrap::operator=(FragTrap& s) {
	std::cout << "\x1B[2m[FragTrap copy assignment operator called] (" << _name << ")\x1B[22m\n";
	if (this != &s) {
		ClapTrap::operator=(s);
	}
	return (*this);
}

FragTrap::~FragTrap( void ) {
	std::cout << "\x1B[2m[FragTrap destructor called] (" << _name << ")\x1B[22m\n";
}
