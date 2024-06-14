#include "Point.hpp"

Point::Point( void ) : _x(Fixed(0)), _y(Fixed(0)) {}

Point::Point( const float x, const float y ) : _x(Fixed(x)), _y(Fixed(y)) {}

Point::Point( const Point& p ) : _x(p._x), _y(p._y) {}

Point::~Point( void ) {}

const Point&	Point::operator=( const Point& p ) {
	if (this != &p) {
	}
	return (*this);
}

bool	Point::operator==( const Point& p ) { 
	return (this->get_x() == p.get_x() && this->get_y() == p.get_y());
}

Fixed	Point::get_x( void ) const {return this->_x;}
Fixed	Point::get_y( void ) const {return this->_y;}
