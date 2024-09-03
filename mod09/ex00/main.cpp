#include "BitcoinExchange.hpp"

int	main(int argc, char *argv[]) {
	if (argc != 2)
		return ft_error("could not open file.");
	Btc	btc("input/data.csv");
	try {
		btc.read_db();
		btc.calculate(std::string(argv[1]));
	} catch (std::exception &e) {
		return ft_error(e.what());
	}
	return 0;
}
