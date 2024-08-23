#include "Span.hpp"

void	Span::addNumber(int n) {
	if (_num.size() == _N)
		throw VectorFullException();
	_num.push_back(n);
}

void	Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (_num.size() + std::distance(begin, end) > _N)
		throw VectorFullException();
	_num.insert(_num.end(), begin, end);
}

int	Span::shortestSpan() {
	if (_num.size() < 2)
		throw NoSpanException();
	int span = std::numeric_limits<int>::max();
	std::vector<int> sorted(_num);

	std::sort(sorted.begin(), sorted.end());
	for (std::vector<int>::size_type i = 0; i < sorted.size() - 1; i++) {
		if (sorted[i + 1] - sorted[i] < span)
			span = sorted[i + 1] - sorted[i];
	}
	return span;
}

int	Span::longestSpan() {
	if (_num.size() < 2)
		throw NoSpanException();
	int min = *std::min_element(_num.begin(), _num.end());
	int max = *std::max_element(_num.begin(), _num.end());
	return max - min;
}

const char* Span::NoSpanException::what() const throw() {
	return "Span only contains one number or none";
}

const char* Span::VectorFullException::what() const throw() {
	return "Not enough space in Span";
}

Span::Span() : _N(0) {}

Span::Span(unsigned int N) : _N(N) {}

Span::Span(const Span& other) {*this = other;}

Span::~Span() {}

Span& Span::operator=(const Span& other) {
	if (this == &other)
		return *this;
	_N = other._N;
	_num = other._num;
	return *this;
}
