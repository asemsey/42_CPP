#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
public:
	DiamondTrap(const std::string& name);
	DiamondTrap( void );
	DiamondTrap( DiamondTrap& c );
	~DiamondTrap( void );
	DiamondTrap&	operator=(DiamondTrap& s);

	void			whoAmI( void );

private:
	std::string		_name;

};

#endif