#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>
# include <iostream>

template <typename T>
class Array {
public:
	Array() : _arr(NULL), _len(0) {}

	Array(unsigned int n) : _arr(new T[n]()), _len(n) {}

	~Array() {delete[] _arr;}

	Array(const Array& other) : _arr(NULL) {
		*this = other;
	}

	Array& operator=(const Array& other) {
		if (this == &other)
			return *this;
		delete[] _arr;
		_len = other.size();
		_arr = new T[_len];
		for (unsigned int i = 0; i < _len; i++) {
			_arr[i] = other._arr[i];
		}
		return *this;
	}

	T& operator[](int i) const {
		if (i < 0 || static_cast<unsigned int>(i) >= _len)
			throw OutOfBoundsException();
		return _arr[i];
	}

	unsigned int	size() const {return _len;}

	class OutOfBoundsException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Index out of bounds!";
		}
	};

private:
	T				*_arr;
	unsigned int	_len;

};

template <typename T>
std::ostream &operator<<(std::ostream &str, const Array<T>& array) {
	int len = array.size();
	for (int i = 0; i < len; i++) {
		str << array[i];
		if (i < (len - 1))
			str << " - ";
	}
	str << std::endl;
	return str;
}

#endif