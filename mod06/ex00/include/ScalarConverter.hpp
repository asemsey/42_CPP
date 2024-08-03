#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <cmath>
# include <limits>
# include <cerrno>
# include <cstring>

class ScalarConverter
{
public:
	static void	convert(std::string& literal);

private:
	ScalarConverter( void );
	ScalarConverter( ScalarConverter& c );
	ScalarConverter& operator=( ScalarConverter& c);
	~ScalarConverter( void );

};

#endif
