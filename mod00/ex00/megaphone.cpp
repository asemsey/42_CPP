#include <iostream>

char	*ft_upper(char *str)
{
	char	*s = strdup(str);
	int		len = strlen(str);

	for (int i = 0; i < len; i++)
	{
		s[i] = (char)toupper(str[i]);
	}
	return (s);
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < argc; i++)
	{
		std::cout << ft_upper(argv[i]);
	}
	std::cout << '\n';
	return (0);
}
