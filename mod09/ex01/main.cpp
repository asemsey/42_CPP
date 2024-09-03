#include "RPN.hpp"

int main(int argc, char *argv[]) {
	if (argc != 2)
		return ft_err();

	RPN calculator(argv[1]);

	try {
		calculator.solve();
	} catch (std::exception &e) {
		return ft_err();
	}
	calculator.answer();
	return 0;
}