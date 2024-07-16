#include "include/Cat.hpp"
#include <iostream>

void	Cat::makeSound( void ) const {
	std::cout << "Cat: 'Meowww~'\n";
}

void	Cat::think( std::string thought ) {
	_brain->newIdea(thought);
}

void	Cat::remember() {
	_brain->remember();
}

Cat::Cat( void ) : Animal() {
	std::cout << "\x1B[2m[Cat Default constructor called]\x1B[22m\n";
	_type = "Cat";
	_brain = new Brain();
}

Cat::Cat( Cat& c ) : Animal(c) {
	std::cout << "\x1B[2m[Cat Copy constructor called]\x1B[22m\n";
	_brain = NULL;
	*this = c;
}

Cat& Cat::operator=( Cat& c ) {
	std::cout << "\x1B[2m[Cat Copy assignment operator called]\x1B[22m\n";
	Animal::operator=(c);
	if (_brain == NULL) {
		_brain = new Brain(*c._brain);
	} else {
		_brain = c._brain;
	}
	return (*this);
}

Cat::~Cat( void ) {
	std::cout << "\x1B[2m[Cat Destructor called]\x1B[22m\n";
	delete _brain;
}
