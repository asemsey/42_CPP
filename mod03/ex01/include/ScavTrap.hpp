#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap(const std::string& name);
	ScavTrap( void );
	ScavTrap( ScavTrap& c );
	~ScavTrap( void );
	ScavTrap&	operator=(ScavTrap& s);

	void		guardGate();
	void		attack(const std::string& target);

private:
	bool		_guard;

};

// Because you can never have enough ClapTraps, you will now create a derived robot.
// It will be named ScavTrap and will inherit the constructors and destructor from ClapTrap.
// However, its constructors, destructor and attack() will print different messages.
// After all, ClapTraps are aware of their individuality.

// ScavTrap will use the attributes of ClapTrap (update ClapTrap in consequence) and
// must initialize them to:
// • Name, which is passed as parameter to a constructor
// • Hit points (100), represent the health of the ClapTrap
// • Energy points (50)
// • Attack damage (20)

// ScavTrap will also have its own special capacity:
// void guardGate();
// This member function will display a message informing that ScavTrap is now in Gate
// keeper mode.

#endif