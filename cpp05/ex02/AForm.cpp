#include "log.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <stdexcept>
#include <stdint.h>
#include <ostream>
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

const std::invalid_argument AForm::GradeTooHighException = std::invalid_argument("Grade to high.");
const std::invalid_argument AForm::GradeTooLowException = std::invalid_argument("Grade to low.");

AForm::AForm() : _name("12B"), _grade_tosign(150), _grade_toexec(150), _signed(false), _target("Pomme") {
	PRINTLN(BG_BLUE, BLACK, "AForm default constructor.", RESET);
}

AForm::AForm(const string &name, uint8_t grade_tosign, uint8_t grade_toexec) : _name(name), _grade_tosign(grade_tosign), _grade_toexec(grade_toexec), _signed(false), _target("Pomme") {
	PRINTLN(BG_BLUE, BLACK, "AForm constructor.", RESET);
	checkGrade(grade_toexec);
	checkGrade(grade_tosign);
}

AForm::AForm(const AForm &other) : _name(other._name), _grade_tosign(other._grade_tosign), _grade_toexec(other._grade_toexec), _signed(other._signed), _target(other._target) {
	PRINTLN(BG_BLUE, BLACK, "AForm copy constructor.", RESET);
}

AForm::~AForm() {
	PRINTLN(BG_RED, BLACK, "AForm destructor.", RESET);
}

AForm &AForm::operator=(const AForm &other){
	if (this != &other) {
		_signed = other._signed;
		_target = other._target;
	}
	PRINTLN(BG_BLUE, BOLD_BLACK, "AForm assignement operator called.", RESET);

	return (*this);
}

void	AForm::beSigned(Bureaucrat &person)
{
	if (person.getGrade() > _grade_tosign) {
		PRINTLN(person, " couldn't sign ", _name, " because grade to low to sign.");
		return;
	}
	PRINTLN(person, " signed ", _name, ".");
	_signed = true;
}

void	AForm::checkGrade(uint8_t value)
{
	if (value < 1)
		throw this->GradeTooHighException;
	if (value > 150)
		throw this->GradeTooLowException;
}

string	AForm::getName() const { return (_name); }
bool	AForm::getSigned() const { return (_signed); }
uint8_t	AForm::getGradeToExec() const { return (_grade_toexec); }
uint8_t	AForm::getGradeToSign() const { return (_grade_tosign); }

std::ostream&	operator<<(std::ostream& stream, const AForm& obj) {
	return (stream << "AForm[" << obj.getName() << "][" << (int)obj.getGradeToSign() << "][" << (int)obj.getGradeToExec() << "][" << obj.getSigned() << "]");
}
