#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "AForm.hpp"

class Intern
{
public:
	Intern( void );
	Intern( Intern& c );
	Intern& operator=( Intern& c);
	~Intern( void );

	AForm	*makeForm(const std::string& name, const std::string& target);

};

#endif
