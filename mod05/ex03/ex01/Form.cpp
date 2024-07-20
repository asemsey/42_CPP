#include "include/Form.hpp"
#include "include/Bureaucrat.hpp"
#include <iostream>

void	Form::beSigned(Bureaucrat &b) {
	if (b.getGrade() > _signGrade)
		throw GradeTooLowException();
	else
		_signed = true;
}

std::ostream	&operator<<(std::ostream &out, const Form &b) {
	if (b.isSigned())
		return (out << "Form " << b.getName() << ", signed.\n");
	else {
		return (out << "Form " << b.getName()
				<< ", not signed, sign grade: " << b.getSignGrade()
				<< ", grade to execute: " << b.getExecGrade() << ".\n");
	}
}

std::string	Form::getName( void ) const {return (_name);}

bool	Form::isSigned( void ) const {return (_signed);}

int	Form::getSignGrade( void ) const {return (_signGrade);}

int	Form::getExecGrade( void ) const {return (_execGrade);}

// -----------------------------------------------------------------------------

const char* Form::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

// -----------------------------------------------------------------------------

Form::Form( void )
	: _name("Default"), _signed(false), _signGrade(150), _execGrade(150) {
	std::cout << "\x1B[2m[Form Default constructor called]\x1B[22m\n";
}

Form::Form( const std::string& name, int execGrade, int signGrade )
	: _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade) {
	std::cout << "\x1B[2m[Form Constructor called]\x1B[22m\n";
	if (execGrade < 1 || signGrade < 1)
		throw GradeTooHighException();
	if (execGrade > 150 || signGrade > 150)
		throw GradeTooLowException();
}

Form::Form( Form& c )
	: _name(c._name), _signGrade(c._signGrade), _execGrade(c._execGrade) {
	std::cout << "\x1B[2m[Form Copy constructor called]\x1B[22m\n";
	*this = c;
}

Form& Form::operator=( Form& c ) {
	std::cout << "\x1B[2m[Form Copy assignment operator called]\x1B[22m\n";
	if (this != &c) {
		_signed = c._signed;
	}
	return (*this);
}

Form::~Form( void ) {
	std::cout << "\x1B[2m[Form Destructor called]\x1B[22m\n";
}
