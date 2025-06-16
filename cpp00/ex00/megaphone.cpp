#include <cctype>
#include <cstddef>
#include <iostream>
#include <ostream>
#include <string>

int main (int argc, char **argv) {
	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}

	for (int i = 1; i < argc; ++i) {
		std::string arg(argv[i]);
		for (size_t j = 0; j < arg.size(); ++j) {
			arg[j] = std::toupper(arg[j]);
		}
		std::cout << arg;
	}
	std::cout << std::endl;

	return 0;
}