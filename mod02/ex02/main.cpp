#include "Fixed.hpp"

int	main( void )
{
	// subject
	{
		Fixed		a;
		Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );

		std::cout << "a:\t" << a << std::endl;
		std::cout << "++a:\t" << ++a << std::endl;
		std::cout << "a:\t" << a << std::endl;
		std::cout << "a++:\t" << a++ << std::endl;
		std::cout << "a:\t" << a << std::endl;
		std::cout << "b:\t" << b << std::endl;
		std::cout << "max:\t" << Fixed::max( a, b ) << std::endl;
		std::cout << std::endl;
	}
	// more tests
	{
		Fixed	x(1.5f);
		Fixed	y(42);

		std::cout << "x =\t" << x << std::endl;
		std::cout << "y =\t" << y << std::endl;
		std::cout << std::endl;
		std::cout << "x == y\t" << (x == y) << std::endl;
		std::cout << "x != y\t" << (x != y) << std::endl;
		std::cout << "x > y\t" << (x > y) << std::endl;
		std::cout << "x <= y\t" << (x <= y) << std::endl;
		std::cout << "x + y =\t" << (x + y) << std::endl;
		std::cout << "x - y =\t" << (x - y) << std::endl;
		std::cout << "x * y =\t" << (x * y) << std::endl;
		std::cout << "x / y =\t" << (x / y) << std::endl;
		std::cout << "--y\t" << --y << std::endl;
	}
	return (0);
}

// (expected output for subject:)
// 0
// 0.00390625
// 0.00390625
// 0.00390625
// 0.0078125
// 10.1016
// 10.1016
