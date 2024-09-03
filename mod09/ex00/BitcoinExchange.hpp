#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <string>
# include <iostream>
# include <fstream>
# include <algorithm>
# include <exception>
# include <map>

class Btc
{
public:
	Btc( const std::string& db_name );
	Btc( Btc& c );
	Btc& operator=( Btc& c);
	~Btc( void );

	void	calculate( std::string filename );
	bool	read_input(std::ifstream &infile);
	void	read_db( void );

	class FileNotFoundException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

private:
	Btc( void );

	std::map<std::string, float>	_db;
	std::map<std::string, float>::iterator	_found;
	std::string	_input;
	std::string	_db_name;
};

int		ft_error(const std::string &err);

#endif
