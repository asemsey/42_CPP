#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm( void );
	RobotomyRequestForm( const std::string& target );
	RobotomyRequestForm( RobotomyRequestForm& c );
	RobotomyRequestForm& operator=( RobotomyRequestForm& c);
	~RobotomyRequestForm( void );

	void	robotomy( void ) const;
	void	execute(const Bureaucrat &executor) const;

private:
	const std::string	_target;

};

#endif
