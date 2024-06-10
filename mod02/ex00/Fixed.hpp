#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
public:
	Fixed( void );
	Fixed( Fixed& fixed );
	Fixed& operator=( Fixed& fixed);
	~Fixed( void );

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

private:
	int					_number;
	static const int	_fbits = 8;

};

#endif