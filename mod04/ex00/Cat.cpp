#include "include/Cat.hpp"
#include <iostream>

void	Cat::makeSound( void ) const {
	std::cout << "Cat: 'Meowww~'\n";
}

Cat::Cat( void ) : Animal() {
	_type = "Cat";
	std::cout << "\x1B[2m[Cat Default constructor called]\x1B[22m\n";
}

Cat::Cat( Cat& c ) : Animal(c) {
	std::cout << "\x1B[2m[Cat Copy constructor called]\x1B[22m\n";
	*this = c;
}

Cat& Cat::operator=( Cat& c ) {
	std::cout << "\x1B[2m[Cat Copy assignment operator called]\x1B[22m\n";
	Animal::operator=(c);
	return (*this);
}

Cat::~Cat( void ) {
	std::cout << "\x1B[2m[Cat Destructor called]\x1B[22m\n";
}

// ------------------------------------------------------------WrongCat

void	WrongCat::makeSound( void ) const {
	std::cout << "Cat: 'Meowww~'\n";
}

WrongCat::WrongCat( void ) : WrongAnimal() {
	_type = "Cat";
	std::cout << "\x1B[2m[Cat Default constructor called]\x1B[22m\n";
}

WrongCat::WrongCat( WrongCat& c ) : WrongAnimal(c) {
	std::cout << "\x1B[2m[Cat Copy constructor called]\x1B[22m\n";
	*this = c;
}

WrongCat& WrongCat::operator=( WrongCat& c ) {
	std::cout << "\x1B[2m[Cat Copy assignment operator called]\x1B[22m\n";
	WrongAnimal::operator=(c);
	return (*this);
}

WrongCat::~WrongCat( void ) {
	std::cout << "\x1B[2m[Cat Destructor called]\x1B[22m\n";
}
