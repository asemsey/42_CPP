#include "Zombie.hpp"

void	Zombie::announce( void ) {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n";
}

Zombie::Zombie(std::string name) {
	this->name = name;
}

Zombie::Zombie( void ) {
	this->name = "joe";
}

Zombie::~Zombie() {
	std::cout << "deleting " << this->name << "...\n";
}
