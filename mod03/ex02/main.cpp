#include "include/ScavTrap.hpp"
#include "include/FragTrap.hpp"

int	main( void ) {
	FragTrap e;
	FragTrap f("Chad");
	FragTrap g("Nao");

	g.attack("Chad");
	e.attack("Nao");
	e.takeDamage(101);
	e.takeDamage(1);
	e.beRepaired(20);
	f.attack("Nao");
	g.takeDamage(2000);
	f.highFivesGuys();
	// for(int i = 0; i < 101; i++)
	// 	f.attack("some poor dude");
}
