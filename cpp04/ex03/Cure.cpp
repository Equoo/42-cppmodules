
#include "Cure.hpp"
#include "log.hpp"
#include "ICharacter.hpp"

#include <string>
#include <iostream>

using std::string;

Cure::Cure() : AMateria("cure") {}
Cure::Cure(const Cure &other) : AMateria(other) {}
Cure	&Cure::operator=(const Cure &other) {
	if (this != &other) {
		this->type = other.type;
	}
	return (*this);
}
Cure::~Cure() {}

void	Cure::use(ICharacter &target) const {
	PRINTLN("* heals ", target.getName(), "’s wounds *");
};

Cure *Cure::clone() const {
	return (new Cure(*this));
}
