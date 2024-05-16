#include "include/Weapon.hpp"

Weapon::Weapon(std::string type) {
	_type = type;
	std::cout << "[Weapon of type " << type << " created]\n";
}

Weapon::~Weapon( void ) {
	std::cout << "[Weapon destroyed]\n";
}

void	Weapon::setType(std::string type) {
	_type = type;
	std::cout << "Weapon type set to " << _type << std::endl;
}

std::string	Weapon::getType( void ) const {
	return (_type);
}
