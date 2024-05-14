#include "Zombie.hpp"

void	Zombie::set_name( std::string name ) {
	_name = name;
}

void	Zombie::announce( void ) {
	std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}

Zombie::Zombie(std::string name) {
	_name = name;
}

Zombie::Zombie( void ) {
	_name = "joe";
}

Zombie::~Zombie() {
	std::cout << "deleting " << _name << "...\n";
}
