#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
public:
	HumanB(std::string name);
	~HumanB( void );

	std::string	getName( void );
	void		setWeapon(Weapon& weapon);
	void		attack();

private:
	std::string	_name;
	Weapon		*_weapon;

};

#endif