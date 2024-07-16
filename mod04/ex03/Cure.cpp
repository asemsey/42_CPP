#include "include/Cure.hpp"
#include "include/ICharacter.hpp"
#include <iostream>

void		Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}

Cure*	Cure::clone() const {return new Cure(*this);}

std::string const&	Cure::getType() const {return _type;}

// -----------------------------------------------------------------

Cure::Cure( void ) : AMateria("cure") {}

Cure::Cure( const Cure& c ) : AMateria("cure") {*this = c;}

Cure::~Cure( void ) {}

Cure&	Cure::operator=( const Cure& c ) {
	AMateria::operator=(c);
	return (*this);
}

