#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include <string>

class Cure : public AMateria
{
public:
	Cure();
	Cure(const Cure& c);
	Cure& operator=(const Cure& c);
	~Cure();

	std::string const&	getType() const;
	Cure*				clone() const;
	void				use(ICharacter& target);

};

#endif