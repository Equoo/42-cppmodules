#include "log.hpp"
#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <stdexcept>
#include <stdint.h>
#include <ostream>
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

const std::invalid_argument Form::GradeTooHighException = std::invalid_argument("Grade to high.");
const std::invalid_argument Form::GradeTooLowException = std::invalid_argument("Grade to low.");

Form::Form() : _name("12B"), _grade_tosign(150), _grade_toexec(150), _signed(false) {
	PRINTLN(BG_BLUE, BLACK, "Form default constructor.", RESET);
}

Form::Form(const string &name, uint8_t grade_tosign, uint8_t grade_toexec) : _name(name), _grade_tosign(grade_tosign), _grade_toexec(grade_toexec), _signed(false) {
	PRINTLN(BG_BLUE, BLACK, "Form constructor.", RESET);
	checkGrade(grade_toexec);
	checkGrade(grade_tosign);
}

Form::Form(const Form &other) : _name(other._name), _grade_tosign(other._grade_tosign), _grade_toexec(other._grade_toexec), _signed(other._signed) {
	PRINTLN(BG_BLUE, BLACK, "Form copy constructor.", RESET);
}

Form::~Form() {
	PRINTLN(BG_RED, BLACK, "Form destructor.", RESET);
}

Form &Form::operator=(const Form &other){
	if (this != &other) {
		_signed = other._signed;
	}
	PRINTLN(BG_BLUE, BOLD_BLACK, "Form assignement operator called.", RESET);

	return (*this);
}

void	Form::beSigned(Bureaucrat &person)
{
	if (_signed) {
		PRINTLN(person, " couldn't sign ", _name, " because already signed.");
		return;
	}
	if (person.getGrade() > _grade_tosign) {
		PRINTLN(person, " couldn't sign ", _name, " because grade to low to sign.");
		return;
	}
	PRINTLN(person, " signed ", _name, ".");
	_signed = true;
}

void	Form::checkGrade(uint8_t value)
{
	if (value < 1)
		throw this->GradeTooHighException;
	if (value > 150)
		throw this->GradeTooLowException;
}

string	Form::getName() const { return (_name); }
bool	Form::getSigned() const { return (_signed); }
uint8_t	Form::getGradeToExec() const { return (_grade_toexec); }
uint8_t	Form::getGradeToSign() const { return (_grade_tosign); }

std::ostream&	operator<<(std::ostream& stream, const Form& obj) {
	return (stream << "Form[" << obj.getName() << "][" << (int)obj.getGradeToSign() << "][" << (int)obj.getGradeToExec() << "][" << obj.getSigned() << "]");
}
