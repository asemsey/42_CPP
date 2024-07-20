#include "include/ShrubberyCreationForm.hpp"
#include "include/Bureaucrat.hpp"
#include <iostream>
#include <fstream>
#include <exception>

void	ShrubberyCreationForm::createShrubs( void ) const {
	std::ofstream	out;
	out.open((_target + "_shrubbery").c_str());
	out <<	"                ,@@@@@@@,\n"
		<<	"       ,,,.    ,@@@@@@/@@,  .oo8888o.\n"
		<<	"    ,&\%\%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
		<<	"   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
		<<	"   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
		<<	"   %&&%/ %&\%\%&&@@\\ V /@@' `88\\8 `/88'\n"
		<<	"   `&%\\ ` /%&'    |.|        \\ '|8'\n"
		<<	"       |o|        | |         | |\n"
		<<	"       |.|        | |         | |\n"
		<<	"     \\/ ._\\//_/__/  ,\\_//__\\ /.  \\_//_\n";
	out.close();
}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	if (!this->isSigned())
		throw AForm::UnsignedException();
	if (executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();
	createShrubs();
}

// -----------------------------------------------------------------------------

ShrubberyCreationForm::ShrubberyCreationForm( void )
	: AForm("ShubberyCreationForm", 137, 145), _target("target") {
	std::cout << "\x1B[2m[ShrubberyCreationForm Default constructor called]\x1B[22m\n";
}

ShrubberyCreationForm::ShrubberyCreationForm( const std::string& target )
	: AForm("ShubberyCreationForm", 137, 145), _target(target) {
	std::cout << "\x1B[2m[ShrubberyCreationForm Default constructor called]\x1B[22m\n";
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm& c ) : AForm(c) {
	std::cout << "\x1B[2m[ShrubberyCreationForm Copy constructor called]\x1B[22m\n";
	*this = c;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( ShrubberyCreationForm& c ) {
	std::cout << "\x1B[2m[ShrubberyCreationForm Copy assignment operator called]\x1B[22m\n";
	if (this != &c) {
		AForm::operator=(c);
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {
	std::cout << "\x1B[2m[ShrubberyCreationForm Destructor called]\x1B[22m\n";
}
