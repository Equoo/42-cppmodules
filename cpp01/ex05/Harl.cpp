
#include "Harl.hpp"
#include <iostream>
#include <sys/types.h>

Harl::Harl() {}

const std::string	levels[] = {
	"DEBUG",
	"INFO",
	"WARNING",
	"ERROR"
};

void	Harl::complain(std::string level) {
	void (* const level_funcs[])(void) = {
		&debug,
		&info,
		&warning,
		&error
	};

	for (int i = 0; i < 4; i++)
		if (levels[i] == level)
			level_funcs[i]();
}

void	Harl::debug() {
	std::cout << "debuging some code" << std::endl;
}

void	Harl::info() {
	std::cout << "info about something" << std::endl;
}

void	Harl::warning() {
	std::cout << "warning u're to busy for ur egirl" << std::endl;
}

void	Harl::error() {
	std::cout << "error; is ur birth reason." << std::endl;
}
