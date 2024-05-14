#include "Zombie.hpp"

int	main(void)
{
	Zombie	*joe;

	randomChump("ben");
	joe = newZombie("joe");
	joe->announce();
	delete joe;
	return (0);
}
