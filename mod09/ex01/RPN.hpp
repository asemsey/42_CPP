#ifndef RPN_HPP
# define RPN_HPP

#include <string>
#include <stack>
#include <algorithm>
#include <sstream>
#include <iostream>

class RPN
{
public:
	RPN( std::string input );
	virtual ~RPN( void );

	void solve( void );
	int answer( void );

	class ZeroDivisionException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	
	class RpnInputException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

private:
	RPN( RPN& c );
	RPN( void );
	RPN& operator=( RPN& c);
	int do_op( char op );
	std::string				_input;
	std::stack<int>			_calc;
	std::stack<std::string>	_tokens;

};

int ft_err(void);

#endif