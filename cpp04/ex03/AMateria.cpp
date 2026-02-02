#include "log.hpp"
#include "AMateria.hpp"
#include <string>

using std::string;

int AMateria::construct_count = 0;

AMateria::AMateria() : type("") {
	id = construct_count;
	construct_count++;
	PRINTLN(BG_C_GREY, *this, " default construct", RESET);
}
AMateria::AMateria(const string &type) : type(type) {
	id = construct_count;
	construct_count++;
	PRINTLN(BG_C_GREY, *this, " construct", RESET);
}
AMateria::AMateria(const AMateria &other) : type(other.type) {
	id = construct_count;
	construct_count++;
	PRINTLN(BG_C_GREY, *this, " construct copy from ", other, RESET);
}
AMateria	&AMateria::operator=(const AMateria &other) {
	if (this != &other) {
		type = other.type;
	}
	return (*this);
}
AMateria::~AMateria() {
	PRINTLN(BG_C_GREY, *this, " destruct", RESET);
}

string	AMateria::getType() const { return (type); }
int	AMateria::getID() const { return (id); }

std::ostream&	operator<<(std::ostream& stream, const AMateria& obj) {
	return (stream << obj.getType() << "<" << obj.getID() << ">");
}
