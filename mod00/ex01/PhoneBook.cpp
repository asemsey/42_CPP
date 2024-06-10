#include "phonebook.hpp"

PhoneBook::PhoneBook( void ) {
	this->list_size = 0;
}

void	PhoneBook::add_entry(Contact contact) {
	if (this->list_size < 8) {
		this->entries[list_size] = contact;
		this->list_size++;
	}
	else
		this->entries[0] = contact;
}

void	PhoneBook::display( void ) {
	for (int i = 0; i < this->list_size; i++) {
		this->entries[i].display_pub(i + 1);
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

int		PhoneBook::get_size( void ) {
	return list_size;
}

void	PhoneBook::display_one(int index) {
	this->entries[index].display_priv();
}
