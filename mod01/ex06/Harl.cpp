#include "Harl.hpp"

log_level	get_level(std::string& str) {
	if (str == "DEBUG" || str == "debug") return (DEBUG);
	if (str == "INFO" || str == "info") return (INFO);
	if (str == "WARNING" || str == "warning") return (WARNING);
	if (str == "ERROR" || str == "error") return (ERROR);
	return (UNKNOWN);
}

void	Harl::complain(std::string level) {
	log_level	l = get_level(level);
	switch (l) {
		case DEBUG:
			debug();
		case INFO:
			info();
		case WARNING:
			warning();
		case ERROR:
			error();
			break;
		default:
			std::cout << "\n[ Probably complaining about insignificant problems ]\n";
	}
}

void	Harl::debug( void ) {
	std::cout << "\n[DEBUG]   I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n";
}

void	Harl::info( void ) {
	std::cout << "\n[INFO]   I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n";
}

void	Harl::warning( void ) {
	std::cout << "\n[WARNING]   I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month.\n";
}

void	Harl::error( void ) {
	std::cout << "\n[ERROR]   This is unacceptable! I want to speak to the manager now.\n";
}
