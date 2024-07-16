#include "include/Brain.hpp"
#include <iostream>

void	Brain::newIdea( std::string& thought ) {
	_ideas[_ideaCount % 100] = thought;
	_ideaCount++;
}

void	Brain::remember( void ) {
	std::cout << _ideas[(_ideaCount - 1) % 100] << std::endl;
}

Brain::Brain( void ) : _ideaCount(0) {
	std::cout << "\x1B[2m[Brain Default constructor called]\x1B[22m\n";
}

Brain::Brain( Brain& c ) {
	std::cout << "\x1B[2m[Brain Copy constructor called]\x1B[22m\n";
	*this = c;
}

Brain& Brain::operator=( Brain& c ) {
	std::cout << "\x1B[2m[Brain Copy assignment operator called]\x1B[22m\n";
	_ideaCount = c._ideaCount;
	for (unsigned int i = 0; i <= (_ideaCount % 100); i++) {
		_ideas[i] = c._ideas[i];
	}
	return (*this);
}

Brain::~Brain( void ) {
	std::cout << "\x1B[2m[Brain Destructor called]\x1B[22m\n";
}
