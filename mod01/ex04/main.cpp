#include "include/replace.hpp"

// ./replace <filename> <s1> <s2>
int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "Expected arguments: <filename> <s1> <s2>\n";
		return (0);
	}
	replace(argv[1], std::string(argv[2]), std::string(argv[3]));
	return (0);
}
