#include "PmergeMe.hpp"
#include <chrono>

int	main(int argc, char *argv[]) {
	if (argc != 2)
		return ft_error("wrong arguments");
	std::vector<std::string> arg = ft_split(std::string(argv[1]), ' ');
	std::chrono::steady_clock::time_point begin;
	std::chrono::steady_clock::time_point end;
	int size = arg.size();


	// sort with a VECTOR ------------------------------------------
	std::vector<int> vec = to_int_vec(arg);
	if (vec.empty())
		return ft_error("non-numeric argument");
	std::cout << "before:\t" << vec << std::endl;
	
	begin = std::chrono::steady_clock::now();
	vec = mergeSort_vec(vec);
	end = std::chrono::steady_clock::now();

	std::cout << "after:\t" << vec << std::endl;
	std::cout << "Time to process a range of " << size << " elements with std::vector\t: "
			<< (std::chrono::duration<double, std::micro>(end - begin).count()) << " us" << std::endl;


	// sort with a DEQUE --------------------------------------------
	std::deque<int> deq = to_int_deq(arg);
	// std::cout << "before:\t" << deq << std::endl;
	begin = std::chrono::steady_clock::now();
	deq = mergeSort_deq(deq);
	end = std::chrono::steady_clock::now();
	// std::cout << "after:\t" << deq << std::endl;
	std::cout << "Time to process a range of " << size << " elements with std::deque\t: "
			<< (std::chrono::duration<double, std::micro>(end - begin).count()) << " us" << std::endl;
	return 0;
}
