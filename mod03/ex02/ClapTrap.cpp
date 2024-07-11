#include "include/ClapTrap.hpp"
#include <iostream>

void	ClapTrap::attack(const std::string& target) {
	if (_energy && _hitpoints) {
		_energy--;
		std::cout << "ClapTrap " << _name << " attacks " << target
				<< ", causing \033[31m" << _damage << "\033[0m point(s) of damage.\n";
	}
	else if (!_energy) {
		std::cout << "ClapTrap " << _name << " is too tired to attack!\n";
	}
	else
		std::cout << "ClapTrap " << _name << " does not have enough hit points to attack!\n";
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (_hitpoints > amount) {
		_hitpoints -= amount;
		std::cout << "ClapTrap " << _name << " loses \033[31m" << amount
				<< "\033[0m hit point(s). Current points: " << _hitpoints << "\n";
	}
	else if (!_hitpoints)
		std::cout << "ClapTrap " << _name << " is already dead!\n";
	else {
		_hitpoints = 0;
		std::cout << "ClapTrap " << _name << " loses \033[31m" << amount
				<< "\033[0m hit point(s) and dies.\n";
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (_energy) {
		_energy--;
		_hitpoints += amount;
		std::cout << "ClapTrap " << _name << " repairs itself and regains \033[32m"
				<< amount << "\033[0m hit point(s). Current points: " << _hitpoints << "\n";
	}
	else
		std::cout << "ClapTrap " << _name << " is too tired to repair itself!\n";
}

// my own function
void	ClapTrap::status( void ) {
	std::cout << "\033[36mClapTrap " << _name << ": " << _hitpoints << " hit points, "
			<< _energy << " energy points, " << _damage << " attack points.\033[0m\n";
}

// ------------------------------------------------------------------------------------------

ClapTrap::ClapTrap( void ) : _name("Trap"), _hitpoints(10), _energy(10), _damage(0) {
	std::cout << "\x1B[2m[ClapTrap Default constructor called] (Trap)\x1B[22m\n";
}

ClapTrap::ClapTrap( std::string name ) : _name(name), _hitpoints(10), _energy(10), _damage(0) {
	std::cout << "\x1B[2m[ClapTrap Constructor called] (" << name << ")\x1B[22m\n";
}

ClapTrap::ClapTrap( ClapTrap& ct ) {
	std::cout << "\x1B[2m[ClapTrap Copy constructor called] (" << ct._name << ")\x1B[22m\n";
	*this = ct;
}

ClapTrap& ClapTrap::operator=( ClapTrap& ct ) {
	std::cout << "\x1B[2m[ClapTrap Copy assignment operator called] (" << _name << ")\x1B[22m\n";
	_name = ct._name;
	_hitpoints = ct._hitpoints;
	_energy = ct._energy;
	_damage = ct._damage;
	return (*this);
}

ClapTrap::~ClapTrap( void ) {
	std::cout << "\x1B[2m[ClapTrap Destructor called] (" << _name << ")\x1B[22m\n";
}
