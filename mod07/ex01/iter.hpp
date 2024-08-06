#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void	print(T& t) {
	std::cout << t << std::endl;
}

template <typename T>
void	ft_dup(T& x) {
	x = x + x;
}

template <typename T>
void	iter(T *array, size_t len, void (*func)(T &input)) {
	if (!array || len == 0 || !func)
		return ;
	for (size_t i = 0; i < len; i++) {
		func(array[i]);
	}
}

#endif