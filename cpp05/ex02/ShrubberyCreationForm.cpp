#include "log.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <stdexcept>
#include <stdint.h>
#include <ostream>
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreation", 145, 137) {
	PRINTLN(BG_BLUE, BLACK, "ShrubberyCreationForm default constructor.", RESET);
}

ShrubberyCreationForm::ShrubberyCreationForm(const string &target) : AForm("ShrubberyCreation", 145, 137) {
	PRINTLN(BG_BLUE, BLACK, "ShrubberyCreationForm constructor.", RESET);
	_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other) {
	PRINTLN(BG_BLUE, BLACK, "ShrubberyCreationForm copy constructor.", RESET);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	PRINTLN(BG_RED, BLACK, "ShrubberyCreationForm destructor.", RESET);
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other){
	(void)other;
	// if (this != &other) {
	// 	_target = other._target;
	// }
	PRINTLN(BG_BLUE, BOLD_BLACK, "ShrubberyCreationForm assignement operator called.", RESET);

	return (*this);
}

void	ShrubberyCreationForm::toExecute(Bureaucrat &person)
{
	if (!getSigned()) {
		throw std::invalid_argument("FUER");
	}
	if (person.getGrade() > getGradeToExec()) {
		throw this->GradeTooLowException;
	}
	PRINTLN(person, " FEUUURR ", getName(), ".");
}

