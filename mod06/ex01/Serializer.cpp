#include "include/Serializer.hpp"
#include <iostream>

uintptr_t	Serializer::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*		Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}

// -----------------------------------------------------------------------------

Serializer::Serializer( void ) {
	std::cout << "\x1B[2m[Serializer Default constructor called]\x1B[22m\n";
}

Serializer::Serializer( Serializer& c ) {
	std::cout << "\x1B[2m[Serializer Copy constructor called]\x1B[22m\n";
	*this = c;
}

Serializer& Serializer::operator=( Serializer& c ) {
	std::cout << "\x1B[2m[Serializer Copy assignment operator called]\x1B[22m\n";
	if (this != &c) {
		return (*this);
	}
	return (*this);
}

Serializer::~Serializer( void ) {
	std::cout << "\x1B[2m[Serializer Destructor called]\x1B[22m\n";
}
