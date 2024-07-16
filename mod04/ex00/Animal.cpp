#include "include/Animal.hpp"
#include <iostream>

void	Animal::makeSound( void ) const {
	std::cout << "Blobfish: 'BLUB'\n";
}

Animal::Animal( void ) : _type("Blobfish") {
	std::cout << "\x1B[2m[Animal Default constructor called]\x1B[22m\n";
}

Animal::Animal( Animal& c ) {
	std::cout << "\x1B[2m[Animal Copy constructor called]\x1B[22m\n";
	*this = c;
}

Animal& Animal::operator=( Animal& c ) {
	std::cout << "\x1B[2m[Animal Copy assignment operator called]\x1B[22m\n";
	_type = c._type;
	return (*this);
}

Animal::~Animal( void ) {
	std::cout << "\x1B[2m[Animal Destructor called]\x1B[22m\n";
}

// ------------------------------------------------------------WrongAnimal

void	WrongAnimal::makeSound( void ) const {
	std::cout << "Blobfish: 'BLUB'\n";
}

WrongAnimal::WrongAnimal( void ) : _type("Blobfish") {
	std::cout << "\x1B[2m[Animal Default constructor called]\x1B[22m\n";
}

WrongAnimal::WrongAnimal( WrongAnimal& c ) {
	std::cout << "\x1B[2m[Animal Copy constructor called]\x1B[22m\n";
	*this = c;
}

WrongAnimal& WrongAnimal::operator=( WrongAnimal& c ) {
	std::cout << "\x1B[2m[Animal Copy assignment operator called]\x1B[22m\n";
	_type = c._type;
	return (*this);
}

WrongAnimal::~WrongAnimal( void ) {
	std::cout << "\x1B[2m[Animal Destructor called]\x1B[22m\n";
}
