#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include <string>

class Ice : public AMateria
{
public:
	Ice();
	Ice(const Ice& c);
	Ice& operator=(const Ice& c);
	~Ice();

	std::string const&	getType() const;
	Ice*				clone() const;
	void				use(ICharacter& target);

};

#endif