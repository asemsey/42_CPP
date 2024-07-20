#include <string>
#include <iostream>
#include "include/Bureaucrat.hpp"
#include "include/Intern.hpp"

int main( void ) {
	Intern		someRandomIntern;
	Bureaucrat	bob("bob", 46);
	AForm*		rrf;

	rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
	std::cout << bob;
	bob.signForm(*rrf);
	bob.executeForm(*rrf);
	std::cout << *rrf;
	bob.incGrade();
	bob.executeForm(*rrf);

	delete rrf;
	return (0);
}
