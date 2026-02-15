
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "log.hpp"
#include "main.hpp"
#include <iostream>
#include <string>

#define TITLE(x) PRINTLN(BOLD_BLUE, \
		"\n---------------------------------", \
		"\n------------ ", x, " ------------", \
		"\n---------------------------------", \
		RESET)

using std::string;

void	test_assignements() {
	test_one_assignement(Bureaucrat("Victor", 23));
	test_one_assignement(Form("A12", 56, 56));
}

void	test_copies() {
	test_one_copy(Bureaucrat("Victor", 23));
	test_one_copy(Form("A12", 56, 56));
}

void	test_bureaucrat_exceptions() {
	try {
		Bureaucrat	a("Feur", 250);
	} catch (std::exception & e) {
		PRINTLN("It work well: ", e.what());
	}
	try {
		Bureaucrat	a("Feur", 0);
	} catch (std::exception & e) {
		PRINTLN("It work well: ", e.what());
	}
	try {
		Bureaucrat	a("Feur", 150);
		PRINTLN("INFO: ", a);
		a.gradeIncrement();
		PRINTLN("Incremented: ", a);
		a.gradeDecrement();
		PRINTLN("Decremented: ", a);
		PRINTLN("Try to decremented: ", a);
		a.gradeDecrement();
		PRINTLN("Decremented: ", a);
	} catch (std::exception & e) {
		PRINTLN("It work well: ", e.what());
	}
	try {
		Bureaucrat	a("Feur", 1);
		PRINTLN("INFO: ", a);
		a.gradeDecrement();
		PRINTLN("Decremented: ", a);
		a.gradeIncrement();
		PRINTLN("Incremented: ", a);
		PRINTLN("Try to incremented: ", a);
		a.gradeIncrement();
		PRINTLN("Incremented: ", a);
	} catch (std::exception & e) {
		PRINTLN("It work well: ", e.what());
	}
}

void	test_form_exceptions() {
	try {
		Form	a("Feur3B", 0, 1);
	} catch (std::exception & e) {
		PRINTLN("It work well: ", e.what());
	}
	try {
		Form	a("Feur3B", 250, 1);
	} catch (std::exception & e) {
		PRINTLN("It work well: ", e.what());
	}
	try {
		Form	a("Feur3B", 25, 0);
	} catch (std::exception & e) {
		PRINTLN("It work well: ", e.what());
	}
	try {
		Form	a("Feur3B", 25, 250);
	} catch (std::exception & e) {
		PRINTLN("It work well: ", e.what());
	}
	try {
		Bureaucrat	a("Singer", 26);
		Form		form("5B", 25, 25);
		PRINTLN("Form state: ", form);
		PRINTLN("Bureaucrat state: ", a);
		a.signForm(form);
		PRINTLN("Form state: ", form);
		a.gradeIncrement();
		PRINTLN("Incremented: ", a);
		a.signForm(form);
		PRINTLN("Form state: ", form);
	} catch (std::exception & e) {
		PRINTLN("It didn't work well: ", e.what());
	}
}

int main( void ) {
	TITLE("Assignements");
	test_assignements();

	TITLE("Copies");
	test_copies();

	TITLE("bureaucrat Exceptions");
	test_bureaucrat_exceptions();

	TITLE("Form Exceptions");
	test_form_exceptions();
}
