#include "include/PresidentialPardonForm.hpp"
#include "include/Bureaucrat.hpp"
#include <iostream>
#include <exception>

void	PresidentialPardonForm::pardon( void ) const {
	std::cout << _target << " has been pardoned by president Zaphod Beeblebrox\n";
}

void	PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	if (!this->isSigned())
		throw AForm::UnsignedException();
	if (executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();
	pardon();
}

// -----------------------------------------------------------------------------

PresidentialPardonForm::PresidentialPardonForm( void )
	: AForm("PresidentialPardonForm", 5, 25), _target("target") {
	std::cout << "\x1B[2m[PresidentialPardonForm Default constructor called]\x1B[22m\n";
}

PresidentialPardonForm::PresidentialPardonForm( const std::string& target )
	: AForm("PresidentialPardonForm", 5, 25), _target(target) {
	std::cout << "\x1B[2m[PresidentialPardonForm Default constructor called]\x1B[22m\n";
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm& c ) : AForm(c) {
	std::cout << "\x1B[2m[PresidentialPardonForm Copy constructor called]\x1B[22m\n";
	*this = c;
}

PresidentialPardonForm& PresidentialPardonForm::operator=( PresidentialPardonForm& c ) {
	std::cout << "\x1B[2m[PresidentialPardonForm Copy assignment operator called]\x1B[22m\n";
	if (this != &c) {
		AForm::operator=(c);
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm( void ) {
	std::cout << "\x1B[2m[PresidentialPardonForm Destructor called]\x1B[22m\n";
}
