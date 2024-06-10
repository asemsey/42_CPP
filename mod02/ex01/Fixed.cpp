#include "Fixed.hpp"

Fixed::Fixed( void ) : _number(0) {
	std::cout << "Default constructor called\n";
}

Fixed::Fixed( const Fixed& fixed ) {
	std::cout << "Copy constructor called\n";
	*this = fixed;
}

Fixed::Fixed( const int n ) {
	std::cout << "Int constructor called\n";
	_number = n << _fbits;
}

Fixed::Fixed( const float f ) {
	std::cout << "Float constructor called\n";
	_number = roundf(f * (1 << _fbits));
}

Fixed& Fixed::operator=( const Fixed& fixed ) {
	std::cout << "Copy assignment operator called\n";
	if (this != &fixed)
		_number = fixed._number;
	return (*this);
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called\n";
}

float	Fixed::toFloat( void ) const {
	return ((float)_number / (1 << _fbits));
}

int		Fixed::toInt( void ) const {
	return (_number >> _fbits);
}

int	Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called\n";
	return _number;
}

void	Fixed::setRawBits( const int raw ) {
	_number = raw;
}

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed) {
	return (out << fixed.toFloat());
}
