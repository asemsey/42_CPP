#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
public:
	Animal( void );
	Animal( Animal& c );
	Animal& operator=( Animal& c);
	virtual ~Animal( void );

	std::string			getType( void ) const;
	virtual void		makeSound( void ) const = 0;

protected:
	std::string		_type;

};

#endif