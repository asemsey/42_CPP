#include "Fixed.hpp"

// --------------------------------------------------------- operator overloads

bool	Fixed::operator<( const Fixed& f ) { return _number < f._number; }

bool	Fixed::operator>( const Fixed& f ) { return _number > f._number; }

bool	Fixed::operator==( const Fixed& f ) { return _number == f._number; }

bool	Fixed::operator!=( const Fixed& f ) { return _number != f._number; }

bool	Fixed::operator<=( const Fixed& f ) { return _number <= f._number; }

bool	Fixed::operator>=( const Fixed& f ) { return _number >= f._number; }

float	Fixed::operator+( const Fixed& f ) { return this->toFloat() + f.toFloat(); }

float	Fixed::operator-( const Fixed& f ) { return this->toFloat() - f.toFloat(); }

float	Fixed::operator*( const Fixed& f ) { return this->toFloat() * f.toFloat(); }

float	Fixed::operator/( const Fixed& f ) { return this->toFloat() / f.toFloat(); }

// ++f
Fixed&	Fixed::operator++( void ) {
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

// --f
Fixed&	Fixed::operator--( void ) {
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

// f++
Fixed	Fixed::operator++( int ) {
	Fixed	tmp = *this;
	this->setRawBits(this->getRawBits() + 1);
	return (tmp);
}

// f--
Fixed	Fixed::operator--( int ) {
	Fixed	tmp = *this;
	this->setRawBits(this->getRawBits() - 1);
	return (tmp);
}

// ---------------------------------------------------------------- min and max

Fixed&	Fixed::min(Fixed &f1, Fixed &f2) {
	if (f1 <= f2)
		return (f1);
	return (f2);
}

Fixed&	Fixed::max(Fixed &f1, Fixed &f2) {
	if (f1 >= f2)
		return (f1);
	return (f2);
}

const Fixed&	Fixed::min(const Fixed &f1, const Fixed &f2) {
	if (f1.toFloat() <= f2.toFloat())
		return (f1);
	return (f2);
}

const Fixed&	Fixed::max(const Fixed &f1, const Fixed &f2) {
	if (f1.toFloat() >= f2.toFloat())
		return (f1);
	return (f2);
}

// ---------------------------- functions from ex01 ----------------------------

// Constructors
Fixed::Fixed( void ) : _number(0) {
	// std::cout << "Default constructor called\n";
}

Fixed::Fixed( const Fixed& fixed ) {
	// std::cout << "Copy constructor called\n";
	*this = fixed;
}

Fixed::Fixed( const int n ) {
	// std::cout << "Int constructor called\n";
	_number = n << _fbits;
}

Fixed::Fixed( const float f ) {
	// std::cout << "Float constructor called\n";
	_number = roundf(f * (1 << _fbits));
}

// Destructor
Fixed::~Fixed( void ) {
	// std::cout << "Destructor called\n";
}

float	Fixed::toFloat( void ) const {
	return ((float)_number / (1 << _fbits));
}

int		Fixed::toInt( void ) const {
	return (_number >> _fbits);
}

int	Fixed::getRawBits( void ) const {
	// std::cout << "getRawBits member function called\n";
	return _number;
}

void	Fixed::setRawBits( const int raw ) {
	_number = raw;
}

// --------------------------------------------------------- operator overloads

Fixed& Fixed::operator=( const Fixed& f ) {
	// std::cout << "Copy assignment operator called\n";
	if (this != &f)
		_number = f._number;
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed) {
	return (out << fixed.toFloat());
}
