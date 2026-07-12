
#include "BitcoinExchange.hpp"
#include <exception>
#include <iostream>
#include <ostream>
int main( int argc, char **argv ) {
	if (argc != 2) {
		std::cout << "Usage: ./btc [input file Path]" << std::endl;
		return 0;
	}

	BitcoinExchange be;
	try {
		be.loadData();
		be.exchange(argv[1]);
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}
