#include "Fixed.hpp"

int	main( void )
{
	Fixed		a;
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );
	// Fixed		c = b;

	std::cout << "a:\t" << a << std::endl;
	std::cout << "++a:\t" << ++a << std::endl;
	std::cout << "a:\t" << a << std::endl;
	std::cout << "a++:\t" << a++ << std::endl;
	std::cout << "a:\t" << a << std::endl;
	std::cout << "b:\t" << b << std::endl;
	// std::cout << "b / a:\t" << c / a << std::endl;
	// std::cout << "b * a:\t" << c * a << std::endl;
	// std::cout << "b == a:\t" << int(c == a) << std::endl;
	std::cout << "max:\t" << Fixed::max( a, b ) << std::endl;
	return 0;
}

// (expected output:)
// 0
// 0.00390625
// 0.00390625
// 0.00390625
// 0.0078125
// 10.1016
// 10.1016
