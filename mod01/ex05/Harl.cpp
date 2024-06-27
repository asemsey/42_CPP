#include "Harl.hpp"

Harl::Harl( void ) {
	functionMap.insert(std::make_pair("DEBUG", &Harl::debug));
	functionMap.insert(std::make_pair("INFO", &Harl::info));
	functionMap.insert(std::make_pair("WARNING", &Harl::warning));
	functionMap.insert(std::make_pair("ERROR", &Harl::error));
}

void	Harl::complain( std::string level ) {
	std::map<std::string, void (Harl::*)()>::iterator	it;

	it = functionMap.find(level);
	if (it != functionMap.end())
		(this->*(it->second))();
	else
		std::cout << "unknown complaint: '" << level << "'\n";
}

void	Harl::debug( void ) {
	std::cout << "[DEBUG] I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n";
}

void	Harl::info( void ) {
	std::cout << "[INFO] I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n";
}

void	Harl::warning( void ) {
	std::cout << "[WARNING] I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month.\n";
}

void	Harl::error( void ) {
	std::cout << "[ERROR] This is unacceptable! I want to speak to the manager now.\n";
}
