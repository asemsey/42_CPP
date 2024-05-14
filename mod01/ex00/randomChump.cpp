#include "Zombie.hpp"

void	randomChump( std::string name ) {
	Zombie	joe = Zombie(name);
	joe.announce();
}
