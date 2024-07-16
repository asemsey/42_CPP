#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"
# include <string>

class Character : public ICharacter
{
public:
	Character();
	Character(std::string name);
	Character( Character& c );
	Character& operator=( Character& c);
	~Character();

	std::string const&	getName() const;
	void				showPockets();
	void				equip(AMateria* m);
	void				unequip(int idx);
	void				use(int idx, ICharacter& target);

private:
	std::string	_name;
	AMateria	*_inventory[4];
	int			_amount;
};

#endif