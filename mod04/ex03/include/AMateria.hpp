#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>

class ICharacter;

class AMateria
{
public:
	AMateria(std::string const& type);
	AMateria();
	AMateria(const AMateria& c);
	AMateria& operator=(const AMateria& c);
	virtual ~AMateria();

	std::string const&	getType() const;
	virtual AMateria*	clone() const = 0;
	virtual void		use(ICharacter& target);

protected:
	std::string			_type;

};

#endif