#include "include/Bureaucrat.hpp"
#include "include/AForm.hpp"
#include <iostream>
#include <exception>

void	Bureaucrat::executeForm(const AForm& form) {
	try {
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	} catch(const std::exception& e) {
		std::cout << _name << " could'nt execute " << form.getName()
				<< " because: " << e.what() << '\n';
	}
}

void	Bureaucrat::signForm( AForm &f ) {
	try {
		f.beSigned(*this);
		std::cout << _name << " signed " << f.getName() << ".\n";
	} catch (std::exception& e) {
		std::cout << _name << " couldn't sign " << f.getName()
				<< " because: " << e.what() << '\n';
	}
}

void	Bureaucrat::incGrade( void ) {
	if (_grade == 0)
		throw GradeTooHighException();
	else
		_grade--;
}

void	Bureaucrat::decGrade( void ) {
	if (_grade == 150)
		throw GradeTooLowException();
	else
		_grade++;
}

std::string	Bureaucrat::getName( void ) const {return (_name);}

int	Bureaucrat::getGrade( void ) const {return (_grade);}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &b) {
	return (out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".\n");
}

// -----------------------------------------------------------------------------

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high (1-150)";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low (1-150)";
}

// -----------------------------------------------------------------------------

Bureaucrat::Bureaucrat( void ) : _name("Default"), _grade(150) {
	std::cout << "\x1B[2m[Bureaucrat Default constructor called]\x1B[22m\n";
}

Bureaucrat::Bureaucrat( const std::string& name, int grade ) : _name(name) {
	std::cout << "\x1B[2m[Bureaucrat constructor called]\x1B[22m\n";
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
	_grade = grade;
}

Bureaucrat::Bureaucrat( Bureaucrat& c ) {
	std::cout << "\x1B[2m[Bureaucrat Copy constructor called]\x1B[22m\n";
	*this = c;
}

Bureaucrat& Bureaucrat::operator=( Bureaucrat& c ) {
	std::cout << "\x1B[2m[Bureaucrat Copy assignment operator called]\x1B[22m\n";
	if (this != &c)
		_grade = c._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat( void ) {
	std::cout << "\x1B[2m[Bureaucrat Destructor called]\x1B[22m\n";
}
