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
Fixed::Fixed( void ) : _number(0) {}

Fixed::Fixed( const Fixed& fixed ) : _number(fixed._number) {
	*this = fixed;
}

Fixed::Fixed( const int n ) : _number(n << _fbits) {}

Fixed::Fixed( const float f ) : _number(roundf(f * (1 << _fbits))) {}

// Destructor
Fixed::~Fixed( void ) {}

int	Fixed::getRawBits( void ) const { return _number; }
void	Fixed::setRawBits( const int raw ) { _number = raw; }

float	Fixed::toFloat( void ) const {
	return ((float)_number / (1 << _fbits));
}

int		Fixed::toInt( void ) const {
	return (_number >> _fbits);
}

// --------------------------------------------------------- operator overloads

Fixed&	Fixed::operator=(const Fixed &f) {
	if (this != &f)
		this->_number = f.getRawBits();
	return *this;
}

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed) {
	return (out << fixed.toFloat());
}
