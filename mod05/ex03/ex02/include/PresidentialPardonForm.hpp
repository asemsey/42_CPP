#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm( void );
	PresidentialPardonForm( const std::string& target );
	PresidentialPardonForm( PresidentialPardonForm& c );
	PresidentialPardonForm& operator=( PresidentialPardonForm& c);
	~PresidentialPardonForm( void );

	void	pardon( void ) const;
	void	execute(const Bureaucrat &executor) const;

private:
	const std::string	_target;

};

#endif
