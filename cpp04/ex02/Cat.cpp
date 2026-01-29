#include "log.hpp"
#include "Cat.hpp"
#include <iostream>
#include <string>

using std::string;

Cat::Cat() {
	PRINTLN(BG_BLUE, BLACK, "Cat default constructor.", RESET);
	type = "cat";
	brain = new Brain();
}

Cat::Cat(const Cat &other) {
	PRINTLN(BG_BLUE, BLACK, "Cat copy constructor.", RESET);
	type = "cat";
	brain = new Brain(*other.brain);
}

Cat::~Cat() {
	PRINTLN(BG_RED, BLACK, "Cat destructor.", RESET);
	delete brain;
}

Cat &Cat::operator=(const Cat &other) {
	if (this != &other) {
		type = other.type;
		delete brain;
		brain = new Brain(*other.brain);
	}
	PRINTLN(BG_BLUE, BOLD_BLACK, "Cat assignement operator called.", RESET);

	return (*this);
}

void	Cat::makeSound() const {
	PRINTLN("Miaou. T'a une clope ?");
}


