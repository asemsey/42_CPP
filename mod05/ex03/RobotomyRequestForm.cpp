#include "include/RobotomyRequestForm.hpp"
#include "include/Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>

void	RobotomyRequestForm::robotomy( void ) const {
	std::cout << "* loud drilling noises * ";
	if (std::rand() % 2 == 0)
		std::cout << _target << " has been robotomized.\n";
	else
		std::cout << _target << "'s robotomy has failed\n";
}

void	RobotomyRequestForm::execute(const Bureaucrat &executor) const {
	if (!this->isSigned())
		throw AForm::UnsignedException();
	if (executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();
	robotomy();
}

// -----------------------------------------------------------------------------

RobotomyRequestForm::RobotomyRequestForm( void )
	: AForm("RobotomyRequestForm", 45, 72), _target("target") {
	std::cout << "\x1B[2m[RobotomyRequestForm Default constructor called]\x1B[22m\n";
	std::srand(static_cast<unsigned int>(std::time(0)));
}

RobotomyRequestForm::RobotomyRequestForm( const std::string& target )
	: AForm("RobotomyRequestForm", 45, 72), _target(target) {
	std::cout << "\x1B[2m[RobotomyRequestForm Default constructor called]\x1B[22m\n";
	std::srand(static_cast<unsigned int>(std::time(0)));
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm& c ) : AForm(c) {
	std::cout << "\x1B[2m[RobotomyRequestForm Copy constructor called]\x1B[22m\n";
	std::srand(static_cast<unsigned int>(std::time(0)));
	*this = c;
}

RobotomyRequestForm& RobotomyRequestForm::operator=( RobotomyRequestForm& c ) {
	std::cout << "\x1B[2m[RobotomyRequestForm Copy assignment operator called]\x1B[22m\n";
	if (this != &c) {
		AForm::operator=(c);
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm( void ) {
	std::cout << "\x1B[2m[RobotomyRequestForm Destructor called]\x1B[22m\n";
}
