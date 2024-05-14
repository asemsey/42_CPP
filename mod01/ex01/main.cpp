#include "Zombie.hpp"

int	main(void)
{
	Zombie		*horde;
	int			hordeSize = 4;
	std::string	name = "joe";

	horde = zombieHorde(hordeSize, name);
	for (int i = 0; i < hordeSize; i++) {
		horde[i].announce();
	}
	delete[] horde;
	return (0);
}
