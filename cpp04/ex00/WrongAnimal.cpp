#include "log.hpp"
#include "WrongAnimal.hpp"
#include <ostream>
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

WrongAnimal::WrongAnimal() : type("") {
	PRINTLN(BG_CYAN, BLACK, "WrongAnimal default constructor.", RESET);
}

WrongAnimal::WrongAnimal(const string &type) : type(type) {
	PRINTLN(BG_CYAN, BLACK, "WrongAnimal constructor(type).", RESET);
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : type(other.type) {
	PRINTLN(BG_CYAN, BLACK, "WrongAnimal copy constructor.", RESET);
}

WrongAnimal::~WrongAnimal() {
	PRINTLN(BG_YELLOW, BLACK, "WrongAnimal destructor.", RESET);
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
	if (this != &other) {
		type = other.type;
	}
	PRINTLN(BG_CYAN, GREEN, "WrongAnimal assignement operator called.", RESET);

	return (*this);
}

std::ostream&	operator<<(std::ostream& stream, const WrongAnimal& obj) {
	return (stream << "WrongAnimal[" << obj.getType() << "]");
}

string	WrongAnimal::getType() const { return (type); }

void	WrongAnimal::makeSound() const {}


