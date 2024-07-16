#include "include/Dog.hpp"
#include <iostream>

void	Dog::makeSound( void ) const {
	std::cout << "Dog: 'Woof!'\n";
}

Dog::Dog( void ) : Animal() {
	_type = "Dog";
	std::cout << "\x1B[2m[Dog Default constructor called]\x1B[22m\n";
}

Dog::Dog( Dog& c ) : Animal(c) {
	std::cout << "\x1B[2m[Dog Copy constructor called]\x1B[22m\n";
	*this = c;
}

Dog& Dog::operator=( Dog& c ) {
	std::cout << "\x1B[2m[Dog Copy assignment operator called]\x1B[22m\n";
	Animal::operator=(c);
	return (*this);
}

Dog::~Dog( void ) {
	std::cout << "\x1B[2m[Dog Destructor called]\x1B[22m\n";
}
