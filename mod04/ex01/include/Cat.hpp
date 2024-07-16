#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <string>

class Cat : public Animal
{
public:
	Cat( void );
	Cat( Cat& c );
	Cat& operator=( Cat& c);
	virtual ~Cat( void );

	void	makeSound( void ) const ;
	void	think( std::string thought );
	void	remember( void );

private:
	Brain	*_brain;

};

#endif