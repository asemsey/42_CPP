#include "phonebook.hpp"

std::string	ft_itoa(int n) {
	std::ostringstream oss;
	oss << n;
	return oss.str();
}

int	ft_getdigit(std::string str) {
	if (str.length() == 1 && '0' <= str[0] && str[0] <= '9')
		return ((int)(str[0] - '0'));
	return (-1);
}

std::string	prompt_input(std::string prompt)
{
	std::string	var = "";

	while (var.empty())
	{
		std::cout << prompt;
		getline(std::cin, var);
		if (std::cin.eof() == true)
		{
			std::cout << std::endl;
			std::cin.clear();
			clearerr(stdin);//c function, prevents ctrl+d infinite loop
		}
	}
	return (var);
}

int	empty_book(PhoneBook book)
{
	std::string	input;

	if (book.get_size() == 0)
	{
		std::cout << "no entries found, use ADD command to add entries";
		getline(std::cin, input);
		return (1);
	}
	return (0);
}

void	command_search(PhoneBook book)
{
	int			index = 1;
	std::string	input = "";

	if (empty_book(book))
		return ;
	std::cout << "searching entries... (type exit to cancel)\n";
	while (true)
	{
		book.display();
		std::cout << std::endl;
		input = prompt_input("enter the index of the entry you would like to read: ");
		if (input == "exit")
			return ;
		index = ft_getdigit(input);
		if (index > 0 && index <= book.get_size())
			break ;
		std::cout << "please enter a number from the list\n";
	}
	std::cout << "chosen entry: " << index << std::endl << std::endl;
	book.display_one(index - 1);
	std::cout << "\npress enter to return to menu";
	getline(std::cin, input);
}

// first name, last name, nickname, phone number, darkest secret
Contact	command_add(void)
{
	std::string	input;
	Contact	contact;

	std::cout << "adding new contact...\n";
	contact.set_firstname(prompt_input("first name: "));
	contact.set_lastname(prompt_input("last name: "));
	contact.set_nickname(prompt_input("nickname: "));
	contact.set_phone(prompt_input("phone number: "));
	contact.set_secret(prompt_input("darkest secret: "));
	std::cout << "Contact added successfully :)\npress enter to return to menu";
	getline(std::cin, input);
	return (contact);
}

int	main(void)
{
	std::string		input;
	PhoneBook		book;

	std::cout << "---Hello! Welcome to PhoneBook---\n";
	while (true)
	{
		input = prompt_input("[commands: 1-ADD | 2-SEARCH | 3-EXIT] -> ");
		if (input.empty())
			continue ;
		if (input == "EXIT" || input == "3")
			break ;
		else if (input == "SEARCH" || input == "2")
			command_search(book);
		else if (input == "ADD" || input == "1")
			book.add_entry(command_add());
	}
	std::cout << "goodbye! (deleting all entries)\n";
	return (0);
}
