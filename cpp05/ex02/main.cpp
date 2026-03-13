
#include "main.hpp"

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "log.hpp"

#define TITLE(x)                                                                    \
	PRINTLN(BOLD_BLUE, "\n---------------------------------", "\n------------ ", x, \
			" ------------", "\n---------------------------------", RESET)

using std::string;

void test_assignements() {
	test_one_assignement(Bureaucrat("Victor", 23));
	test_one_assignement(ShrubberyCreationForm("Coiffeur"));
}

void test_copies() {
	test_one_copy(Bureaucrat("Victor", 23));
	test_one_copy(ShrubberyCreationForm("Coiffeur"));
}

void test_bureaucrat_exceptions() {
	try {
		Bureaucrat a("Feur", 250);
	} catch (std::exception& e) {
		PRINTLN("It work well: ", e.what());
	}
	try {
		Bureaucrat a("Feur", 0);
	} catch (std::exception& e) {
		PRINTLN("It work well: ", e.what());
	}
	try {
		Bureaucrat a("Feur", 150);
		PRINTLN("INFO: ", a);
		a.gradeIncrement();
		PRINTLN("Incremented: ", a);
		a.gradeDecrement();
		PRINTLN("Decremented: ", a);
		PRINTLN("Try to decremented: ", a);
		a.gradeDecrement();
		PRINTLN("Decremented: ", a);
	} catch (std::exception& e) {
		PRINTLN("It work well: ", e.what());
	}
	try {
		Bureaucrat a("Feur", 1);
		PRINTLN("INFO: ", a);
		a.gradeDecrement();
		PRINTLN("Decremented: ", a);
		a.gradeIncrement();
		PRINTLN("Incremented: ", a);
		PRINTLN("Try to incremented: ", a);
		a.gradeIncrement();
		PRINTLN("Incremented: ", a);
	} catch (std::exception& e) {
		PRINTLN("It work well: ", e.what());
	}
}

void test_form_exceptions() {
	try {
		Bureaucrat a("Singer", 145);
		ShrubberyCreationForm form("Coiffeur");
		ShrubberyCreationForm formB("Coiffeur 2");
		PRINTLN("AForm state: ", form);
		a.signForm(form);
		PRINTLN("AForm state: ", form);
		a.gradeDecrement();
		a.signForm(form);
		PRINTLN("AForm state: ", form);
		a.signForm(formB);
	} catch (std::exception& e) {
		PRINTLN("It didn't work well: ", e.what());
	}
}

void test_form_executes() {
	try {
		test_execute_form(RobotomyRequestForm("Nicolas"));
		test_execute_form(PresidentialPardonForm("Capitol"));
		test_execute_form(ShrubberyCreationForm("Louis"));
	} catch (std::exception& e) {
		PRINTLN("It didn't work well: ", e.what());
	}
}

int main(void) {
	srand(time(NULL))

	TITLE("Assignements");
	test_assignements();

	TITLE("Copies");
	test_copies();

	TITLE("bureaucrat Exceptions");
	test_bureaucrat_exceptions();

	TITLE("AForm Exceptions");
	test_form_exceptions();

	TITLE("Forms executes");
	test_form_executes();
}
