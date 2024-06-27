#include "Harl.hpp"

int	main(int argc, char *argv[])
{
	Harl		harl;

	if (argc != 2)
		std::cout << "\n[ Probably complaining about insignificant problems ]\n";
	else
		harl.complain(std::string(argv[1]));
	std::cout << std::endl;
	return (0);
}
