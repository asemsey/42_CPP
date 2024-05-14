# include <string>
# include <iostream>

int	main(void)
{
	std::string		brain = "HI THIS IS BRAIN";
	std::string		*stringPTR = &brain;
	std::string&	stringREF = brain;

	std::cout << "address of string:	" << &brain << std::endl
			<< "stringPTR:		" << stringPTR << std::endl
			<< "stringREF:		" << stringREF << std::endl
			<< "the string:		" << brain << std::endl
			<< "stringPTR points to:	" << *stringPTR << std::endl
			<< "stringREF points to:	" << stringREF << std::endl;
	return (0);
}
