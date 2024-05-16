#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
public:
	HumanA(std::string name, Weapon& weapon);
	~HumanA( void );

	void		setName(std::string type);
	std::string getName( void );
	void		attack();

private:
	std::string	_name;
	Weapon&		_weapon;

};

#endif