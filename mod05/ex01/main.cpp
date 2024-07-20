#include <string>
#include <iostream>
#include "include/Bureaucrat.hpp"
#include "include/Form.hpp"

int main( void ) {
	try {
		Bureaucrat	a("Jeff", 9);
		Bureaucrat	b("Greg", 64);
		Form		f("something important", 50, 20);
		// Form		f("something important", 50, 0);

		std::cout << a;
		std::cout << b;
		std::cout << f << std::endl;

		b.signForm(f);
		a.signForm(f);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	return (0);
}
