#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"
# include <cmath>
# include <iostream>

class Point
{
public:
	Point( void );
	Point( const float x, const float y );
	Point( const Point& p );
	~Point( void );

	const Point&	operator=( const Point& p );
	bool			operator==( const Point& p );

	Fixed	get_x( void ) const ;
	Fixed	get_y( void ) const ;

private:
	const Fixed		_x;
	const Fixed		_y;

};

Fixed	slope(Point a, Point b);
bool	bsp( Point const a, Point const b, Point const c, Point const point);

#endif