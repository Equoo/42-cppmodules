#include "ShrubberyCreationForm.hpp"

#include <stdint.h>

#include <exception>
#include <fstream>
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

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreation", 145, 137) {
	PRINTLN(BG_BLUE, BLACK, "ShrubberyCreationForm default constructor.", RESET);
}

ShrubberyCreationForm::ShrubberyCreationForm(const string &target)
	: AForm("ShrubberyCreation", 145, 137) {
	PRINTLN(BG_BLUE, BLACK, "ShrubberyCreationForm constructor.", RESET);
	_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other) {
	PRINTLN(BG_BLUE, BLACK, "ShrubberyCreationForm copy constructor.", RESET);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	PRINTLN(BG_RED, BLACK, "ShrubberyCreationForm destructor.", RESET);
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(
	const ShrubberyCreationForm &other) {
	*static_cast<AForm *>(this) = other;
	PRINTLN(BG_BLUE, BOLD_BLACK,
			"ShrubberyCreationForm assignement operator called.", RESET);

	return (*this);
}
void ShrubberyCreationForm::execute(Bureaucrat const &person) const {
	checkExecute(person);

	std::string filename = _target;
	filename.append("_shrubbery");
	std::ofstream outFile;

	outFile.exceptions ( std::ifstream::failbit | std::ifstream::badbit );
	outFile.open(filename.c_str());
	outFile << TREE_ASCII;
	outFile.close();
}
