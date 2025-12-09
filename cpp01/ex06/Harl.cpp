
#include "Harl.hpp"
#include <iostream>
#include <sys/types.h>

void Harl::complain(t_harl_level level) const {
	switch (level) {
	  case HARL_DEBUG:
		debug();
	  case HARL_INFO:
		info();
	  case HARL_WARNING:
		warning();
	  case HARL_ERROR:
		error();
	  default:
		return;
  }
}

void	Harl::debug() const {
	std::cout << "debuging some code" << std::endl;
}

void	Harl::info() const {
	std::cout << "info about something" << std::endl;
}

void	Harl::warning() const {
	std::cout << "warning u're to busy for ur egirl" << std::endl;
}

void	Harl::error() const {
	std::cout << "error; is ur birth reason." << std::endl;
}

