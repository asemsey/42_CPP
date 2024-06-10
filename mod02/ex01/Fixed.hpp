#ifndef FIXED_HPP
# define FIXED_HPP

# include <cmath>
# include <iostream>

class Fixed
{
public:
	Fixed( void );
	Fixed( const Fixed& fixed );
	Fixed( const int n );
	Fixed( const float f );
	~Fixed( void );

	Fixed&	operator=( const Fixed& fixed );

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;

private:
	int					_number;
	static const int	_fbits = 8;

};

std::ostream	&operator<<(std::ostream &str, Fixed const &fixed_nbr);

#endif