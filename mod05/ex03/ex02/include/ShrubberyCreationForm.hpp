#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

// ShrubberyCreationForm: Required grades: sign 145, exec 137
// Create a file <target>_shrubbery in the working directory,
// and writes ASCII trees inside it.

class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm( void );
	ShrubberyCreationForm( const std::string& target );
	ShrubberyCreationForm( ShrubberyCreationForm& c );
	ShrubberyCreationForm& operator=( ShrubberyCreationForm& c);
	~ShrubberyCreationForm( void );

	void	createShrubs( void ) const ;
	void	execute(const Bureaucrat &executor) const;

private:
	const std::string	_target;

};

#endif
