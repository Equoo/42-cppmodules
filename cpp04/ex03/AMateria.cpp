#include "log.hpp"
#include "AMateria.hpp"
#include <string>

using std::string;

AMateria::AMateria() : type("") {}
AMateria::AMateria(const string &type) : type(type){
}
AMateria::AMateria(const AMateria &other) : type(other.type) {
}
AMateria	&AMateria::operator=(const AMateria &other) {
	if (this != &other) {
		type = other.type;
	}
	return (*this);
}
AMateria::~AMateria() {}

string	AMateria::getType() const { return (type); }


