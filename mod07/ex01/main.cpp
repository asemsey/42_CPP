#include "iter.hpp"
#include <string>

int main( void ) {
	int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::string str[] = {"hello", "world"};

	std::cout << "ints after dup:\n";
	iter(arr, 10, ft_dup<int>);
	iter(arr, 10, print<int>);
	std::cout << std::endl;

	std::cout << "strings after dup:\n";
	iter(str, 2, ft_dup<std::string>);
	iter(str, 2, print<std::string>);
	return 0;
}
