#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <vector>
# include <limits>
# include <exception>

class Span {
public:
	Span();
	Span(unsigned int N);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	void			addNumber(int n);
	void			addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	int				shortestSpan();
	int				longestSpan();

	class NoSpanException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	
	class VectorFullException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

private:
	unsigned int		_N;
	std::vector<int>	_num;

};

#endif
