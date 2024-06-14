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

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;

	Fixed&	operator=(const Fixed &f);
	bool	operator<( const Fixed& f );
	bool	operator>( const Fixed& f );
	bool	operator==( const Fixed& f );
	bool	operator!=( const Fixed& f );
	bool	operator<=( const Fixed& f );
	bool	operator>=( const Fixed& f );

	float	operator+( const Fixed& f );
	float	operator-( const Fixed& f );
	float	operator*( const Fixed& f );
	float	operator/( const Fixed& f );

	Fixed&	operator++( void );//++f
	Fixed&	operator--( void );//--f
	Fixed	operator++( int );//f++
	Fixed	operator--( int );//f--

	static const Fixed	&min(const Fixed &f1, const Fixed &f2);
	static Fixed		&min(Fixed &f1, Fixed &f2);
	static const Fixed	&max(const Fixed &f1, const Fixed &f2);
	static Fixed		&max(Fixed &f1, Fixed &f2);


private:
	int					_number;
	static const int	_fbits = 8;

};

std::ostream	&operator<<(std::ostream &str, Fixed const &fixed_nbr);

#endif