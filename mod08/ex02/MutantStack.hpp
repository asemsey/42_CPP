#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
public:
	MutantStack(void) : std::stack<T>() {}
	MutantStack(const MutantStack& other) : std::stack<T>(other) {}
	~MutantStack(void) {}

	MutantStack& operator=(const MutantStack& other) {
		if (this != &other)
			std::stack<T>::operator=(other);
		return *this;
	}

	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

	iterator				begin(void) {return std::stack<T>::c.begin();}
	iterator				end(void) {return std::stack<T>::c.end();}
	const_iterator			cbegin(void) const {return std::stack<T>::c.begin();}
	const_iterator			cend(void) const {return std::stack<T>::c.end();}
	reverse_iterator		rbegin(void) {return std::stack<T>::c.rbegin();}
	reverse_iterator		rend(void) {return std::stack<T>::c.rend();}
	const_reverse_iterator	crbegin(void) const {return std::stack<T>::c.rbegin();}
	const_reverse_iterator	crend(void) const {return std::stack<T>::c.rend();}

};

#endif
