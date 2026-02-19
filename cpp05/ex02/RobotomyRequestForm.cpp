#include "RobotomyRequestForm.hpp"

#include <stdint.h>

#include <cstdlib>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <string>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "log.hpp"

using std::cout;
using std::endl;
using std::string;

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequest", 72, 45) {
	PRINTLN(BG_BLUE, BLACK, "RobotomyRequestForm default constructor.", RESET);
}

RobotomyRequestForm::RobotomyRequestForm(const string &target)
	: AForm("RobotomyRequest", 72, 45) {
	PRINTLN(BG_BLUE, BLACK, "RobotomyRequestForm constructor.", RESET);
	_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: AForm(other) {
	PRINTLN(BG_BLUE, BLACK, "RobotomyRequestForm copy constructor.", RESET);
}

RobotomyRequestForm::~RobotomyRequestForm() {
	PRINTLN(BG_RED, BLACK, "RobotomyRequestForm destructor.", RESET);
}

RobotomyRequestForm &RobotomyRequestForm::operator=(
	const RobotomyRequestForm &other) {
	*static_cast<AForm *>(this) = other;
	PRINTLN(BG_BLUE, BOLD_BLACK, "RobotomyRequestForm assignement operator called.",
			RESET);

	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &person) const {
	checkExecute(person);

	PRINTLN("BBRRRRRZZZZZzzrrrZZzZzzZZ");
	if (std::rand() % 2 == 1)
		PRINTLN(_target, " has been robotomized.");
	else
		PRINTLN(_target, " is dead );");
}
