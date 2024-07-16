#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include <string>

class Cat : public Animal
{
public:
	Cat( void );
	Cat( Cat& c );
	Cat& operator=( Cat& c);
	~Cat( void );

	void	makeSound( void ) const ;

};

class WrongCat : public WrongAnimal
{
public:
	WrongCat( void );
	WrongCat( WrongCat& c );
	WrongCat& operator=( WrongCat& c);
	~WrongCat( void );

	void	makeSound( void ) const ;

};

#endif