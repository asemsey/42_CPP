#include "include/ScavTrap.hpp"

int	main( void ) {
	{
		ScavTrap c;
		ScavTrap d("Nao");

		c.attack("Rob");
		// for (int i = 0; i < 50; i++)
		// 	c.attack("Jeff");
		c.beRepaired(22);
		c.takeDamage(21);
		c.beRepaired(22);
		c.guardGate();
		c.guardGate();
		d.attack("R2");
		d.takeDamage(101);
		d.takeDamage(15);
		d.attack("Pi");
	}
	// {
	// 	ScavTrap s("Nao");
	// 	ScavTrap b("Pi");

	// 	s.status();
	// 	s.attack("Pi");
	// 	b.takeDamage(99);
	// 	b.takeDamage(5);
	// 	b.attack("Nao");
	// 	b.guardGate();
	// 	b.guardGate();
	// 	s.status();
	// 	b.status();
	// 	b.beRepaired(20);
	// }
}
