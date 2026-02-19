#include "PresidentialPardonForm.hpp"

#include <stdint.h>

#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "log.hpp"

using std::cout;
using std::endl;
using std::string;

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardon", 25, 5) {
	PRINTLN(BG_BLUE, BLACK, "PresidentialPardonForm default constructor.", RESET);
}

PresidentialPardonForm::PresidentialPardonForm(const string &target)
	: AForm("PresidentialPardon", 25, 5) {
	PRINTLN(BG_BLUE, BLACK, "PresidentialPardonForm constructor.", RESET);
	_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
	: AForm(other) {
	PRINTLN(BG_BLUE, BLACK, "PresidentialPardonForm copy constructor.", RESET);
}

PresidentialPardonForm::~PresidentialPardonForm() {
	PRINTLN(BG_RED, BLACK, "PresidentialPardonForm destructor.", RESET);
}

PresidentialPardonForm &PresidentialPardonForm::operator=(
	const PresidentialPardonForm &other) {
	*static_cast<AForm *>(this) = other;
	PRINTLN(BG_BLUE, BOLD_BLACK, "PresidentialPardonForm assignement operator called.",
			RESET);

	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &person) const {
	checkExecute(person);

	PRINTLN(_target, " has been pardoned by Zaphod Beeblebrox.");
}
