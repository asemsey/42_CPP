#include "include/AMateria.hpp"
#include "include/ICharacter.hpp"
#include <iostream>

void	AMateria::use(ICharacter& target) {(void)target;}

std::string const&	AMateria::getType() const {return _type;}

// -----------------------------------------------------------------

AMateria::AMateria( void ) : _type("Default") {}

AMateria::AMateria( std::string const& type ) : _type(type) {}

AMateria::AMateria( const AMateria& c ) {
	*this = c;
	_type = c._type;
}

AMateria::~AMateria( void ) {}

AMateria&	AMateria::operator=( const AMateria& c ) {
	(void)c;
	return (*this);
}

