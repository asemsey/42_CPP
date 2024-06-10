#include <iostream>
#include <string>

std::string	ft_upper(std::string str)
{
	std::string s = str;

	for (int i = 0; i < (int)str.length(); i++)
	{
		if (('a' <= str[i] && str[i] <= 'z'))
			s[i] = (str[i] - 32);
	}
	return (s);
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < argc; i++)
	{
		std::cout << ft_upper(std::string(argv[i]));
	}
	std::cout << std::endl;
	return (0);
}
