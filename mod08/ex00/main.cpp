#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main(void) {
	int					array[] = {42, 0, 505, 69, 53, 666, -273};
	int					tofind = 0;

	std::vector<int>	vec(array, array + 7);
	std::list<int>		lst(array, array + 7);
	std::deque<int>		deq(array, array + 7);

	try {
		std::vector<int>::iterator found1 = easyfind(vec, tofind);
		std::cout << "found number in vector: " << *found1 << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::list<int>::iterator found2 = easyfind(lst, tofind);
		std::cout << "found number in list: " << *found2 << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::deque<int>::iterator found3 = easyfind(deq, tofind);
		std::cout << "found number in deque: " << *found3 << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
