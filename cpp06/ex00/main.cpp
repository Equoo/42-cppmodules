
#include "ScalarConverter.hpp"
#include "log.hpp"
#include <iostream>
#include <string>

using std::string;

int main(int argc, char **argv) {
	if (argc != 2) {
		PRINTLN("Error\nUsage: ./bin <value>");
		return (1);
	}

	ScalarConverter::convert(string(argv[1]));
	return (0);
}
