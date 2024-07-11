#include "include/ClapTrap.hpp"

int	main( void ) {
	ClapTrap a("Pi");
	ClapTrap b("Nao");

	a.status();
	b.status();
	std::cout << std::endl;
	a.attack("Nao");
	a.takeDamage(10);
	a.takeDamage(1);
	a.beRepaired(5);
	a.attack("Nao");
	b.beRepaired(3);
	for (int i = 0; i < 10; i++)
		b.attack("Pi");
	b.beRepaired(3);
	std::cout << std::endl;
	a.status();
	b.status();
}
