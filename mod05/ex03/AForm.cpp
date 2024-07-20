#include "include/AForm.hpp"
#include "include/Bureaucrat.hpp"
#include <iostream>
#include <exception>

void	AForm::beSigned(Bureaucrat &b) {
	if (b.getGrade() > _signGrade)
		throw GradeTooLowException();
	else
		_signed = true;
}

std::ostream	&operator<<(std::ostream &out, const AForm &b) {
	if (b.isSigned()) {
		return (out << "Form " << b.getName()
				<< ", signed, grade to execute: " << b.getExecGrade() << ".\n");
	} else {
		return (out << "Form " << b.getName()
				<< ", not signed, sign grade: " << b.getSignGrade()
				<< ", grade to execute: " << b.getExecGrade() << ".\n");
	}
}

std::string	AForm::getName( void ) const {return (_name);}

bool	AForm::isSigned( void ) const {return (_signed);}

int	AForm::getSignGrade( void ) const {return (_signGrade);}

int	AForm::getExecGrade( void ) const {return (_execGrade);}

// -----------------------------------------------------------------------------

const char* AForm::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

const char* AForm::UnsignedException::what() const throw() {
	return "Form has not been signed";
}

// -----------------------------------------------------------------------------

AForm::AForm( void )
	: _name("Default"), _signed(false), _signGrade(150), _execGrade(150) {
	std::cout << "\x1B[2m[Form Default constructor called]\x1B[22m\n";
}

AForm::AForm( const std::string& name, int execGrade, int signGrade )
	: _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade) {
	std::cout << "\x1B[2m[Form Constructor called]\x1B[22m\n";
	if (execGrade < 1 || signGrade < 1)
		throw GradeTooHighException();
	if (execGrade > 150 || signGrade > 150)
		throw GradeTooLowException();
}

AForm::AForm( AForm& c )
	: _name(c._name), _signGrade(c._signGrade), _execGrade(c._execGrade) {
	std::cout << "\x1B[2m[Form Copy constructor called]\x1B[22m\n";
	*this = c;
}

AForm& AForm::operator=( AForm& c ) {
	std::cout << "\x1B[2m[Form Copy assignment operator called]\x1B[22m\n";
	if (this != &c) {
		_signed = c._signed;
	}
	return (*this);
}

AForm::~AForm( void ) {
	std::cout << "\x1B[2m[Form Destructor called]\x1B[22m\n";
}
