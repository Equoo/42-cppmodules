#include "log.hpp"
#include "WrongCat.hpp"
#include <iostream>
#include <string>

using std::string;

WrongCat::WrongCat() : WrongAnimal("cat") {
	PRINTLN(BG_BLUE, BLACK, "WrongCat default constructor.", RESET);
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other.type) {
	PRINTLN(BG_BLUE, BLACK, "WrongCat copy constructor.", RESET);
}

WrongCat::~WrongCat() {
	PRINTLN(BG_RED, BLACK, "WrongCat destructor.", RESET);
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
	if (this != &other) {
		type = other.type;
	}
	PRINTLN(BG_BLUE, GREEN, "WrongCat assignement operator called.", RESET);

	return (*this);
}

void	WrongCat::makeSound() const {
	PRINTLN("Miaou. T'a une clope ?");
}


