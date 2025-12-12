
#include <cstdlib>
#include <exception>
#include <istream>
#include <limits>
#include <ostream>
#include <stdexcept>
#include <string>
#include <iostream>
#include <sys/types.h>

using std::cin;
using std::cout;

static bool	has_extra_input() {
    return !cin.eof() && cin.peek() != '\n';
}

static void	ignore_line() {
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::string	prompt(std::string prompt, bool is_line) {
	std::string	response;
	
	cout << prompt << " ➜ ";
	if (is_line)
		std::getline(cin >> std::ws, response);
	else
		cin >> response;
	if (!cin) {
		if (cin.eof()) {
			cin.clear();
			throw std::invalid_argument("You must use EXIT to end the process.");
		}

		cin.clear();
		ignore_line();
		throw std::invalid_argument("Invalid input.");
	}	

	return (response);
}

int prompt_int(std::string prompt) {
	int	response;
	
	cout << prompt << " ➜ ";	
	cin >> response;
	if (!cin) {
		if (cin.eof()) {
			std::exit(0);
		}

		cin.clear();
		ignore_line();
		throw std::invalid_argument("Invalid input: must be a int.");
	}
	if (has_extra_input()) {
		ignore_line();
		throw std::invalid_argument("Invalid input: must be a int.");
	}

	return (response);
}
