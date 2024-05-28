#include "Fixed.hpp"

Fixed::Fixed( void ) : _number(0) {
	std::cout << "Default constructor called\n";
}

Fixed::Fixed( Fixed& fixed ) {
	std::cout << "Copy constructor called\n";
	_number = fixed.getRawBits();
}

Fixed& Fixed::operator=( Fixed& fixed ) {
	std::cout << "Copy assignment operator called\n";
	_number = fixed.getRawBits();
	return (*this);
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called\n";
}

int	Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called\n";
	return _number;
}

void	Fixed::setRawBits( int const raw ) {
	_number = raw;
}
