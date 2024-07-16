#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include <string>

class Dog: public Animal
{
public:
	Dog( void );
	Dog( Dog& c );
	Dog& operator=( Dog& c);
	~Dog( void );

	void	makeSound( void ) const ;

};

#endif