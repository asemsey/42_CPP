#include "include/Intern.hpp"
#include "include/ShrubberyCreationForm.hpp"
#include "include/RobotomyRequestForm.hpp"
#include "include/PresidentialPardonForm.hpp"
#include <iostream>

AForm *shrubbery(const std::string& target) {
	return (new ShrubberyCreationForm(target));
}

AForm *president(const std::string& target) {
	return (new PresidentialPardonForm(target));
}

AForm *robotomy(const std::string& target) {
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::makeForm(const std::string& name, const std::string& target) {
	AForm *(*forms[])(const std::string& target) = {&president, &robotomy, &shrubbery};
	std::string names[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};

	for (int i = 0; i < 3; i++) {
		if (name == names[i]) {
			std::cout << "Intern creates " << name << std::endl;
			return (forms[i](target));
		}
	}
	std::cout << "Intern couldn't create form of type " << name << std::endl;
	return (NULL);
}

// ------------------------------------------------------------------------

Intern::Intern( void ) {
	std::cout << "\x1B[2m[Intern Default constructor called]\x1B[22m\n";
}

Intern::Intern( Intern& c ) {
	std::cout << "\x1B[2m[Intern Copy constructor called]\x1B[22m\n";
	*this = c;
}

Intern& Intern::operator=( Intern& c ) {
	std::cout << "\x1B[2m[Intern Copy assignment operator called]\x1B[22m\n";
	if (this != &c)
		return (*this);
	return (*this);
}

Intern::~Intern( void ) {
	std::cout << "\x1B[2m[Intern Destructor called]\x1B[22m\n";
}
