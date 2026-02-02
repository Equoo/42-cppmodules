
#include "Ice.hpp"
#include "log.hpp"
#include "ICharacter.hpp"

#include <string>
#include <iostream>

using std::string;

Ice::Ice() : AMateria("ice") {}
Ice::Ice(const Ice &other) : AMateria(other) {}
Ice	&Ice::operator=(const Ice &other) {
	if (this != &other) {
		this->type = other.type;
	}
	return (*this);
}
Ice::~Ice() {}


Ice *Ice::clone() const {
	return (new Ice(*this));
}
void	Ice::use(ICharacter &target) const {
	PRINTLN(MAGENTA, "* shoots an ice bolt at ", target.getName(), " *", RESET);
};
