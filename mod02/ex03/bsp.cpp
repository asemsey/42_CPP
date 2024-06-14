#include "Fixed.hpp"
#include "Point.hpp"

// Subject:
// • a, b, c: The vertices of our beloved triangle.
// • point: The point to check.
// • Returns: True if the point is inside the triangle. False otherwise.
// Thus, if the point is a vertex or on edge, it will return False.

bool	is_triangle(Point a, Point b, Point c);
float	area(Point const a, Point const b, Point const c);
float	slope(Point a, Point b);

// point forms a triange with two points each. if areas add up to the main triangles area
// the point is inside the triangle (the three triangles together can form the main traingle)
bool	bsp( Point const a, Point const b, Point const c, Point const point) {
	if (!is_triangle(a, b, point) || !is_triangle(b, c, point) || !is_triangle(c, a, point))
		return (false);
	return (area(a, b, point) + area(b, c, point) + area(c, a, point) == area(a, b, c));
}


float	slope(Point a, Point b) {
	Fixed dy = b.get_y() - a.get_y();
	Fixed dx = b.get_x() - a.get_x();
	return (dy / dx);
}

bool	is_triangle(Point a, Point b, Point c) {
	return (!(a == b || b == c || c == a || slope(a, b) == slope(b, c)));
}

float	area(Point const a, Point const b, Point const c) {
	Fixed x1 = a.get_x() * (b.get_y() - c.get_y());
	Fixed x2 = b.get_x() * (c.get_y() - a.get_y());
	Fixed x3 = c.get_x() * (a.get_y() - b.get_y());
	float	area = x1.toFloat() + x2.toFloat() + x3.toFloat();
	if (area < 0)
		area = -area;
	return (0.5 * area);
}
