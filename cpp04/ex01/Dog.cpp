#include "log.hpp"
#include "Dog.hpp"
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

Dog::Dog() : Animal("dog") {
	PRINTLN(BG_BLUE, BLACK, "Dog default constructor.", RESET);
	brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other.type) {
	PRINTLN(BG_BLUE, BLACK, "Dog copy constructor.", RESET);
	brain = new Brain(*other.brain);
}

Dog::~Dog() {
	PRINTLN(BG_RED, BLACK, "Dog destructor.", RESET);
	delete brain;
}

Dog &Dog::operator=(const Dog &other) {
	if (this != &other) {
		type = other.type;
		delete brain;
		brain = new Brain(*other.brain);
	}
	PRINTLN(BG_BLUE, BOLD_BLACK, "Dog assignement operator called.", RESET);

	return (*this);
}

void	Dog::makeSound() const {
	PRINTLN("Bark, bark, ouaf.");
}


