#include "Fixed.hpp"
#include "Point.hpp"

int	main( void )
{
	Point	p1 = Point(1, 0);
	Point	p2 = Point(p1);
	Point	p3;

	p2 = p3;//doesnt actually do anything (const)

	std::cout << "p1\t" << p1.get_x() << " " << p1.get_y() << std::endl;//a
	std::cout << "p2\t" << p2.get_x() << " " << p2.get_y() << std::endl;//==p1
	std::cout << "p3\t" << p3.get_x() << " " << p3.get_y() << std::endl;//b

	Point	p4 = Point(1, 3);
	Point	inside = Point(0.99, 1.4555);

	std::cout << "p4\t" << p4.get_x() << " " << p4.get_y() << std::endl;//c
	std::cout << "inside\t" << inside.get_x() << " " << inside.get_y() << std::endl;//point

	// triangle check
	if (bsp(p1, p3, p4, inside))
		std::cout << "the point is inside the triangle :)\n";
	else
		std::cout << "the point is not inside the triangle :(\n";
}
