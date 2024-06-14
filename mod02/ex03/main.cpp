#include "Fixed.hpp"
#include "Point.hpp"

int	main( void )
{
	Point	a = Point(1, 0);
	Point	b;
	Point	c = Point(1, 3);
	Point	p = Point(a);

	p = b;//doesnt do anything (const)

	std::cout << "a\t" << a.get_x() << " " << a.get_y() << std::endl;
	std::cout << "b\t" << b.get_x() << " " << b.get_y() << std::endl;
	std::cout << "c\t" << c.get_x() << " " << c.get_y() << std::endl;
	std::cout << "p\t" << p.get_x() << " " << p.get_y() << std::endl;

	Point	inside = Point(0.99, 1.4555);//inside
	// Point	inside = Point(1.1, 1.4555);//outside
	// Point	inside = Point(1, 1.4555);//edge
	// Point	inside = Point(1, 3);//vertex

	std::cout << "inside\t" << inside.get_x() << " " << inside.get_y() << std::endl;

	// triangle check
	if (bsp(a, b, c, inside))
		std::cout << "the point is inside the triangle :)\n";
	else
		std::cout << "the point is not inside the triangle :(\n";
}
