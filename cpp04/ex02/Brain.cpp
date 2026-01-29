#include "log.hpp"
#include "Brain.hpp"
#include <ostream>
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

Brain::Brain() {
	PRINTLN(BG_MAGENTA, BLACK, "Brain default constructor.", RESET);
	for (int i = 0; i < 100; i++)
		ideas[i] = "No idea.";
}

Brain::Brain(const Brain &other) {
	PRINTLN(BG_MAGENTA, BLACK, "Brain copy constructor.", RESET);
	for (int i = 0; i < 100; i++)
		ideas[i] = other.ideas[i];
}

Brain::~Brain() {
	PRINTLN(BG_GREEN, BLACK, "Brain destructor.", RESET);
}

Brain &Brain::operator=(const Brain &other) {
	if (this != &other) {
		for (int i = 0; i < 100; i++)
			ideas[i] = other.ideas[i];
	}
	PRINTLN(BG_CYAN, BOLD_BLACK, "Brain assignement operator called.", RESET);

	return (*this);
}

