#include "include/Ice.hpp"
#include "include/ICharacter.hpp"
#include <iostream>

void		Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}

Ice*	Ice::clone() const {return new Ice(*this);}

std::string const&	Ice::getType() const {return _type;}

// -----------------------------------------------------------------

Ice::Ice() : AMateria("ice") {}

Ice::Ice( const Ice& c ) : AMateria("ice") {*this = c;}

Ice::~Ice() {}

Ice&	Ice::operator=( const Ice& c ) {
	AMateria::operator=(c);
	return (*this);
}

