#include "Intern.hpp"

#include <stdint.h>

#include <cstddef>
#include <exception>
#include <iostream>
#include <string>

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "log.hpp"

using std::string;

const char *Intern::forms[3] = {
	"robotomy request",
	"presidential pardon",
	"shrubbery creation"
};

Intern::Intern() {
	PRINTLN(BG_CYAN, BLACK, "Intern default constructor.", RESET);
}

Intern::Intern(__attribute__((unused)) const Intern &other) {
	PRINTLN(BG_CYAN, BLACK, "Intern copy constructor.", RESET);
}

Intern::~Intern() {
	PRINTLN(BG_YELLOW, BLACK, "Intern destructor.", RESET);
}

Intern &Intern::operator=(__attribute__((unused)) const Intern &other) {
	PRINTLN(BG_CYAN, BOLD_BLACK, "Intern assignement operator called.", RESET);

	return (*this);
}

static void	lower_string(string &str) {
	for (size_t j = 0; j < str.size(); ++j)
	{
		str[j] = std::tolower(str[j]);
	}
}

AForm *Intern::makeForm(string form, const string &target) const {
	int i = 0;

	lower_string(form);
	for (; i < 3; i++)
		if (form == forms[i])
			break;

	switch (i) {
		case PRESIDENTIAL_PARDON:
			PRINTLN("Intern creates ", form);
			return new PresidentialPardonForm(target);
		case ROBOTOMY_REQUEST:
			PRINTLN("Intern creates ", form);
			return new RobotomyRequestForm(target);
		case SHRUBBERY_CREATION:
			PRINTLN("Intern creates ", form);
			return new ShrubberyCreationForm(target);
		default:
			PRINTLN("Intern cannot create ", form, ": doesn't exist.");
			break;
	}
	return (NULL);
}
