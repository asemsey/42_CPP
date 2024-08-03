#include "include/Base.hpp"
#include "include/ABC.hpp"

Base::~Base() {}

Base	*generate(void) {
	int x = rand() % 3;

	switch (x) {
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
		default:
			return NULL;
	}
}

void	identify(Base* p) {
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C" << std::endl;
}

void	identify(Base& p) {
	Base	base;
	try {
		base = dynamic_cast<A&>(p);
		(void)base;
		std::cout << "A" << std::endl;
	} catch (std::exception &e) {}
	try {
		base = dynamic_cast<B&>(p);
		(void)base;
		std::cout << "B" << std::endl;
	} catch (std::exception &e) {}
	try {
		base = dynamic_cast<C&>(p);
		(void)base;
		std::cout << "C" << std::endl;
	} catch (std::exception &e) {}
}