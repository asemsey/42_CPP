#include "phonebook.hpp"

void	Contact::display_pub(int index) {
	std::cout << "|";
	if (index > 0)
	{
		print_ten(ft_itoa(index));
		std::cout << "|";
	}
	print_ten(this->firstname);
	std::cout << "|";
	print_ten(this->lastname);
	std::cout << "|";
	print_ten(this->nickname);
	std::cout << "|";
}

void	Contact::display_priv( void ) {
	display_pub(0);
	print_ten(this->phone);
	std::cout << "|";
	print_ten(this->secret);
	std::cout << "|\n";
}

void	Contact::print_ten(std::string str) {
	if (str.length() <= 10)
		std::cout << std::setw(10) << str;
	else
		std::cout << str.substr(0, 9) << ".";
}

void	Contact::set_firstname(std::string name) {
	this->firstname = name;
}

void	Contact::set_lastname(std::string name) {
	this->lastname = name;
}

void	Contact::set_nickname(std::string name) {
	this->nickname = name;
}

void	Contact::set_phone(std::string number) {
	this->phone = number;
}

void	Contact::set_secret(std::string s) {
	this->secret = s;
}
