#include "BitcoinExchange.hpp"

int	ft_error(const std::string &err) {
	std::cerr << "Error: " << err << std::endl;
	return 1;
}

static bool	is_date(const std::string& line) {
	int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 30, 31};
	if (line.length() < 10)
		return false;
	for (int i = 0; (i < (int)line.length() && line[i] != ',' && line[i] != ' '); i++) {
		if (i < 4 || (4 < i && i < 7) || (7 < i && i < 10)) {
			if (!isdigit(line[i]))
				return false;
		}
		else if (i != 10 && line[i] != '-')
			return false;
	}
	int month = stoi(line.substr(5, 2));
	int day = stoi(line.substr(8, 2));
	if (month > 12 || day > days[month - 1] || day < 1 || month < 1)
		return false;
	return true;
}

static bool	is_float(const std::string& line) {
	int comma = 0;
	if (line.length() < 1)
		return false;
	for (int i = 0; i < (int)line.length(); i++) {
		if (line[i] == '.')
			comma++;
		else if (!isdigit(line[i]))
			return false;
	}
	return (comma < 2 && line[line.length()-1] != '.');
}

float	parse_float(std::string& line) {
	float r = -1;
	if (line.length() > 13) {
		if (line.length() > 17) {
			ft_error("too large a number.");
			return -1;
		}
		try {
			r = stof(line.substr(13));
		} catch (std::exception &e) {
			ft_error("not a positive number.");
			return -1;
		}
		if (r < 0 || !is_float(line.substr(13))) {
			ft_error("not a positive number.");
			return -1;
		}
		if (r > 1000) {
			ft_error("too large a number.");
			return -1;
		}
	}
	return r;
}

// ----------------------------------------------------------------Btc class:

bool	Btc::read_input(std::ifstream &infile) {
	if (!infile.is_open())
		return false;
	if (!std::getline(infile, _input))
		return false;
	return true;
}

void	Btc::calculate( std::string filename ) {
	std::ifstream infile(filename);
	if (!infile.is_open())
		throw FileNotFoundException();
	float mult;
	std::map<std::string, float>::iterator it;
	while (read_input(infile)) {
		if (_input == "date | value")
			continue;
		if (!is_date(_input)) {
			std::cout << "Error: bad input => " << _input << std::endl;
			continue;
		}
		mult = parse_float(_input);
		if (mult < 0)
			continue;
		it = _db.lower_bound(_input.substr(0, 10));
		if (it == _db.end()) {
			ft_error("no data found.");
			continue;
		}
		std::cout << _input.substr(0, 10) << " => " << _input.substr(13) << " = " << (it->second * mult) << std::endl;
	}
}

void	Btc::read_db() {
	if (!_db.empty())
		return ;
	std::ifstream	infile(_db_name);
	std::string		line;
	if (!infile.is_open())
		throw FileNotFoundException();
	while (std::getline(infile, line)) {
		if (line == "date,exchange_rate")
			continue;
		_db[line.substr(0, 10)] = stof(line.substr(11));
	}
}

Btc::Btc( const std::string& db_name ) : _db_name(db_name) {}

Btc::Btc( void ) {}

Btc::Btc( Btc& c ) {
	*this = c;
}

Btc& Btc::operator=( Btc& c ) {
	if (this != &c)
		_db = c._db;
	return (*this);
}

Btc::~Btc( void ) {
	_db.clear();
	_input.clear();
}

const char* Btc::FileNotFoundException::what() const throw() {
	return "could not open file";
}