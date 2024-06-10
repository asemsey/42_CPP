#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iomanip>
#include <string>
#include <iostream>
#include <sstream>
#include <cstdio>

class Contact
{
public:
	void		display_pub(int index);
	void		display_priv( void );

	void		set_firstname(std::string name);
	void		set_lastname(std::string name);
	void		set_nickname(std::string name);
	void		set_phone(std::string number);
	void		set_secret(std::string s);

private:
	std::string	firstname;
	std::string	lastname;
	std::string	nickname;
	std::string	secret;
	std::string	phone;

	void		print_ten(std::string str);
};

class PhoneBook
{
private:
	int			list_size;
	Contact		entries[8];

public:
	PhoneBook( void );

	int			get_size( void );
	void		add_entry(Contact contact);
	void		display( void );
	void		display_one(int index);

};

std::string		ft_itoa(int n);
int				ft_getdigit(std::string str);

#endif