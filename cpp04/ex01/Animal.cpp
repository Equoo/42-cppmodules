#include "log.hpp"
#include "Animal.hpp"
#include <ostream>
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

Animal::Animal() : type("") {
	PRINTLN(BG_CYAN, BLACK, "Animal default constructor.", RESET);
}

Animal::Animal(const string &type) : type(type) {
	PRINTLN(BG_CYAN, BLACK, "Animal constructor(", type, ").", RESET);
}

Animal::Animal(const Animal &other) : type(other.type) {
	PRINTLN(BG_CYAN, BLACK, "Animal copy constructor.", RESET);
}

Animal::~Animal() {
	PRINTLN(BG_YELLOW, BLACK, "Animal destructor.", RESET);
}

Animal &Animal::operator=(const Animal &other) {
	if (this != &other) {
		type = other.type;
	}
	PRINTLN(BG_CYAN, BOLD_BLACK, "Animal assignement operator called.", RESET);

	return (*this);
}

std::ostream&	operator<<(std::ostream& stream, const Animal& obj) {
	return (stream << "Animal[" << obj.getType() << "]");
}

string	Animal::getType() const { return (type); }

void	Animal::makeSound() const {}


