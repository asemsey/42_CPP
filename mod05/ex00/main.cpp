#include <string>
#include <iostream>
#include "include/Bureaucrat.hpp"

int main( void ) {
	try {
		Bureaucrat a("Jeff", 5);
		Bureaucrat b;
		Bureaucrat c("Bob", -123);
		Bureaucrat d("Greg", 151);

		std::cout << a;
		b.decGrade();
		b.incGrade();
		std::cout << b;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	return (0);
}
