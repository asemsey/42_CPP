#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap(const std::string& name);
	FragTrap( void );
	FragTrap( FragTrap& c );
	~FragTrap( void );
	FragTrap&	operator=(FragTrap& s);

	void highFivesGuys(void);

};

#endif