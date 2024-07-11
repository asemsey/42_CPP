#include "include/DiamondTrap.hpp"

int	main( void ) {
	DiamondTrap	diamond("Diamond");

	diamond.attack("target");
	diamond.highFivesGuys();
	diamond.guardGate();
	diamond.guardGate();
	diamond.attack("target");
	diamond.takeDamage(10);
	diamond.beRepaired(10);
	diamond.whoAmI();
	diamond.status();
}
