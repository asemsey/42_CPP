#include "Fixed.hpp"

Fixed::Fixed( void ) : _number(0) {
	std::cout << "Default constructor called\n";
}

Fixed::Fixed( Fixed& fixed ) {
	std::cout << "Copy constructor called\n";
	_number = fixed.getRawBits();
}

Fixed::Fixed( const int n ) {
	std::cout << "Int constructor called\n";
	_number = n << _fbits;
}

Fixed::Fixed( const float f ) {
	std::cout << "Float constructor called\n";
	// 123.45f
	// get 123
	// subtract 123 from f
	// 123 << fbits???
	_number = (int)f;
}

Fixed& Fixed::operator=( Fixed& fixed ) {
	std::cout << "Copy assignment operator called\n";
	_number = fixed.getRawBits();
	return (*this);
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called\n";
}

float	Fixed::toFloat( void ) const {
	return (float)(_number >> _fbits);
}

int		Fixed::toInt( void ) const {
	return (int)(_number >> _fbits);
}

int	Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called\n";
	return _number;
}

void	Fixed::setRawBits( int const raw ) {
	_number = raw;
}

std::ostream	&operator<<(std::ostream &str, Fixed const &fixed) {
	return (str << fixed.toFloat());
}
