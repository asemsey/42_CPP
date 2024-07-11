#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>

class ClapTrap
{
public:
	ClapTrap( void );
	ClapTrap( std::string name );
	ClapTrap( ClapTrap& c );
	virtual ~ClapTrap( void );
	ClapTrap&		operator=( ClapTrap& c);

	void			status( void );
	virtual void	attack(const std::string& target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);

protected:
	std::string		_name;
	unsigned int	_hitpoints;
	unsigned int	_energy;
	unsigned int	_damage;

};

#endif