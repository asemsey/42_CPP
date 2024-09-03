#include "RPN.hpp"

std::stack<std::string> split(const std::string &str, char c) {
	std::stack<std::string>	stack_a;
	std::stack<std::string>	stack_b;

	std::stringstream		ss(str);
	std::string				word;

	while (std::getline(ss, word, c)) {
		if (!word.empty())
			stack_a.push(word);
	}
	while (!stack_a.empty()) {
		stack_b.push(stack_a.top());
		stack_a.pop();
	}
	return stack_b;
}

int ft_err(void) {
	std::cerr << "Error\n";
	return 1;
}

bool is_op(std::string& str) {
	return (str == "+" || str == "-" || str == "*" || str == "/");
}

// ---------------------------------------------------------------RPN

void RPN::solve( void ) {
	int						tmp;
	std::string				token;
	std::string::size_type	rest;
	while (!_tokens.empty()) {
		token = _tokens.top();
		if (is_op(token))
			do_op(token[0]);
		else {
			tmp = std::stoi(token, &rest);
			if (rest != token.length())
				throw RpnInputException();
			_calc.push(tmp);
		}
		_tokens.pop();
	}
}

int RPN::answer( void ) {
	if (_calc.size() != 1) {
		ft_err();
		return 0;
	}
	std::cout << _calc.top() << std::endl;
	return _calc.top();
}

int RPN::do_op( char op ) {
	if (_calc.size() < 2)
		throw RpnInputException();
	int x = _calc.top();
	_calc.pop();
	int y = _calc.top();
	_calc.pop();

	if (op == '+') {
		_calc.push(y + x);
		return (y + x);
	}
	if (op == '-') {
		_calc.push(y - x);
		return (y - x);
	}
	if (op == '*') {
		_calc.push(y * x);
		return (y * x);
	}
	if (op == '/') {
		if (x == 0)
			throw ZeroDivisionException();
		_calc.push(y / x);
		return (y / x);
	}
	return 0;
}

RPN::RPN( std::string input ) : _input(input), _calc(), _tokens() {
	_tokens = split(_input, ' ');
}

RPN::RPN( void ) {}

RPN::RPN( RPN& c ) {
	*this = c;
}

RPN& RPN::operator=( RPN& c ) {
	if (this != &c)
		return (*this);
	return (*this);
}

RPN::~RPN( void ) {}

const char* RPN::RpnInputException::what() const throw() {
	return "rpn string invalid";
}

const char* RPN::ZeroDivisionException::what() const throw() {
	return "division by zero";
}