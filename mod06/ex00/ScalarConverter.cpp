#include "include/ScalarConverter.hpp"

bool	isSpecial(const std::string& l) {
	return (l == "inf" || l == "inff" || l == "+inf" || l == "+inff"
		|| l == "-inf" || l == "-inff" || l == "nan" || l == "nanf");
}

bool	invalidString(const std::string& l) {
	if (l.length() == 1 || isSpecial(l))
		return false;
	std::size_t	i(0);
	int			points(0);
	if (l[0] == '-' || l[0] == '+')
		i++;
	while (i < l.length()) {
		if (l[i] == '.') {
			points++;
			if (!std::isdigit(l[i - 1]))
				return true;
		}
		else if (l[i] == 'f')
			break;
		else if (!std::isdigit(l[i]))
			return true;
		i++;
	}
	if (l[i - 1] == '.')
		return true;
	if ((l[i] == 'f' && (l[i + 1] != '\0' || points != 1)) || points > 1 )
		return true;
	return false;
}

void	toChar(double x) {
	if (x < 0 || 127 < x ) {
		std::cout << "char:\t" << "out of range" << std::endl;
		return;
	}
	char	c = static_cast<char>(x);
	if (std::isprint(c))
		std::cout << "char:\t'" << c << "'" << std::endl;
	else
		std::cout << "char:\t" << "not printable" << std::endl;
}

void	toInt(double x) {
	if (std::isnan(x) || x < std::numeric_limits<int>::min() || std::numeric_limits<int>::max() < x)
		std::cout << "int:\tnot convertable" << std::endl;
	else {
		int		i = static_cast<int>(x);
		std::cout << "int:\t" << i << std::endl;
	}
}

void	toFloat(double x) {
	if (std::isnan(x) || std::isinf(x))
		std::cout << "float:\t" << std::setprecision(1) << static_cast<float>(x) << "f" << std::endl;
	else if (x < -std::numeric_limits<float>::max() || std::numeric_limits<float>::max() < x
		|| (x != 0.0 && (std::abs(x) < std::numeric_limits<float>::min())))
		std::cout << "float:\tnot convertable" << std::endl;
	else
		std::cout << "float:\t" << std::setprecision(1) << static_cast<float>(x) << "f" << std::endl;
}

void	toDouble(double x) {
	std::cout << "double:\t" << std::setprecision(1) << static_cast<double>(x) << std::endl;
}

// -----------------------------------------------------------------------------

void	ScalarConverter::convert(std::string& literal) {
	double	x(0);
	size_t	i(0);

	if (literal.empty()) {
		std::cout << "invalid string: " << literal << std::endl;
		return;
	}
	while (i < literal.length()) {
		if (!std::isspace(literal[i]))
			break;
		i++;
	}
	if (i == literal.length())
		x = literal[i - 1];
	literal = literal.substr(i);
	if (invalidString(literal)) {
		std::cout << "invalid string: " << literal << std::endl;
		return;
	}
	if (literal.length() == 1 && !std::isdigit(literal[0]))
		x = literal[0];
	else if (!x)
		x = atof(literal.c_str());
	std::cout << std::fixed;
	toChar(x);
	toInt(x);
	toFloat(x);
	toDouble(x);
}

// -----------------------------------------------------------------------------

ScalarConverter::ScalarConverter( void ) {
	std::cout << "\x1B[2m[ScalarConverter Default constructor called]\x1B[22m\n";
}

ScalarConverter::ScalarConverter( ScalarConverter& c ) {
	std::cout << "\x1B[2m[ScalarConverter Copy constructor called]\x1B[22m\n";
	*this = c;
}

ScalarConverter& ScalarConverter::operator=( ScalarConverter& c ) {
	std::cout << "\x1B[2m[ScalarConverter Copy assignment operator called]\x1B[22m\n";
	if (this != &c)
		return (*this);
	return (*this);
}

ScalarConverter::~ScalarConverter( void ) {
	std::cout << "\x1B[2m[ScalarConverter Destructor called]\x1B[22m\n";
}
