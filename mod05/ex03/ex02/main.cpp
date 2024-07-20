#include <string>
#include <iostream>
#include "include/Bureaucrat.hpp"
#include "include/ShrubberyCreationForm.hpp"
#include "include/RobotomyRequestForm.hpp"
#include "include/PresidentialPardonForm.hpp"

int main( void ) {
	try {
		Bureaucrat				a("Jeff", 10);
		ShrubberyCreationForm	s("home");
		RobotomyRequestForm		r;
		PresidentialPardonForm	p("Arthur Dent");
		std::cout << a;

		std::cout << r;//robotomy
		a.executeForm(r);
		a.signForm(r);
		a.executeForm(r);
		std::cout << std::endl;

		std::cout << s;//shrubbery
		a.signForm(s);
		a.executeForm(s);
		std::cout << std::endl;

		std::cout << p;//presidential pardon
		a.signForm(p);
		a.executeForm(p);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	return (0);
}
