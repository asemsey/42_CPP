#include "include/Base.hpp"

int main(void) {
	srand(static_cast<unsigned int>(time(0)));
	Base	*base = generate();
	Base&	ref = *base;

	identify(base);
	identify(ref);

	delete base;
	return (0);
}