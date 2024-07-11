#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
public:
	ClapTrap( void );
	ClapTrap( std::string name );
	ClapTrap( ClapTrap& c );
	ClapTrap& operator=( ClapTrap& c);
	~ClapTrap( void );

	void	status( void );
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

private:
	std::string		_name;
	unsigned int	_hitpoints;
	unsigned int	_energy;
	unsigned int	_damage;

};

#endif