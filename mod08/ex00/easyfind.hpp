#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <exception>

class NotFoundException : public std::exception {
public:
	virtual const char* what() const throw() {return "could not find number.";}
};

template <typename T>
typename T::iterator	easyfind(T& cont, int n) {
	typename T::iterator it = std::find(cont.begin(), cont.end(), n);
	if (it == cont.end())
		throw NotFoundException();
	return it;
}

#endif
