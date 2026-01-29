#include "log.hpp"
#include "Cat.hpp"
#include <iostream>
#include <string>

using std::string;

Cat::Cat() : Animal("cat") {
	PRINTLN(BG_BLUE, BLACK, "Cat default constructor.", RESET);
}

Cat::Cat(const Cat &other) : Animal(other.type) {
	PRINTLN(BG_BLUE, BLACK, "Cat copy constructor.", RESET);
}

Cat::~Cat() {
	PRINTLN(BG_RED, BLACK, "Cat destructor.", RESET);
}

Cat &Cat::operator=(const Cat &other) {
	if (this != &other) {
		type = other.type;
	}
	PRINTLN(BG_BLUE, BOLD_BLACK, "Cat assignement operator called.", RESET);

	return (*this);
}

void	Cat::makeSound() const {
	PRINTLN("Miaou. T'a une clope ?");
}


