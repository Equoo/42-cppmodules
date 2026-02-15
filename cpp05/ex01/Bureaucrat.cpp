#include "log.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <stdexcept>
#include <stdint.h>
#include <ostream>
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;


const std::invalid_argument Bureaucrat::GradeTooHighException = std::invalid_argument("Grade to high.");
const std::invalid_argument Bureaucrat::GradeTooLowException = std::invalid_argument("Grade to low.");

Bureaucrat::Bureaucrat() : name("Paul"), grade(150) {
	PRINTLN(BG_CYAN, BLACK, "Bureaucrat default constructor.", RESET);
}

Bureaucrat::Bureaucrat(const string &name, uint8_t grade) : name(name) {
	PRINTLN(BG_CYAN, BLACK, "Bureaucrat constructor.", RESET);
	setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade) {
	PRINTLN(BG_CYAN, BLACK, "Bureaucrat copy constructor.", RESET);
}

Bureaucrat::~Bureaucrat() {
	PRINTLN(BG_YELLOW, BLACK, "Bureaucrat destructor.", RESET);
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other) {
		grade = other.grade;
	}
	PRINTLN(BG_CYAN, BOLD_BLACK, "Bureaucrat assignement operator called.", RESET);

	return (*this);
}

void	Bureaucrat::signForm(Form &form) {
	form.beSigned(*this);
}

string	Bureaucrat::getName() const { return (name); }
uint8_t	Bureaucrat::getGrade() const { return (grade); }

void	Bureaucrat::setGrade(uint8_t grade)
{
	if (grade < 1)
		throw this->GradeTooHighException;
	if (grade > 150)
		throw this->GradeTooLowException;
	this->grade = grade;
}

void	Bureaucrat::gradeIncrement() {
	setGrade(grade - 1);
}

void	Bureaucrat::gradeDecrement() {
	setGrade(grade + 1);
}

std::ostream&	operator<<(std::ostream& stream, const Bureaucrat& obj) {
	return (stream << obj.getName() << ", bureaucrat grade " << (int)obj.getGrade());
}
