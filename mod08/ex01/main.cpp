#include "Span.hpp"
#include <cstdlib>
#include <iostream>

int main()
{
	{
		Span sp = Span(5);

		std::cout << "Making Span with 5 numbers...\n";
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		try {
			std::cout << "trying to add more: ";
			sp.addNumber(12);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}

		std::cout << "shortest:\t" << sp.shortestSpan() << std::endl;
		std::cout << "longest:\t" << sp.longestSpan() << std::endl;
	}
	{
		std::cout << "\nwith 20000 numbers:\n";
		Span				sp = Span(20000);
		std::vector<int>	random;
		srand(time(NULL));
		for (int i = 0; i < 20000; i++)
			random.push_back(rand() % 300000);
		sp.addRange(random.begin(), random.end());

		std::cout << "min:\t\t" << *std::min_element(random.begin(), random.end()) << std::endl
				<< "max:\t\t" << *std::max_element(random.begin(), random.end()) << std::endl
				<< "shortest:\t" << sp.shortestSpan() << std::endl
				<< "longest:\t" << sp.longestSpan() << std::endl;
	}
	return 0;
}