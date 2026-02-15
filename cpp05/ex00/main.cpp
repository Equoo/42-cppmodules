
#include "Bureaucrat.hpp"
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
	Bureaucrat a = Bureaucrat("Victor", 23);
	Bureaucrat	b = Bureaucrat();
	
	PRINTLN("# B = ", b);
	PRINTLN("# Assignement of ", a);
	b = a;
	PRINTLN("# B = ", b);
}

void	test_copies() {
	Bureaucrat a = Bureaucrat("Victor", 23);
	PRINTLN("# A = ", a);
	
	Bureaucrat	b = Bureaucrat(a);
	PRINTLN("# B = ", b);
}

void	test_exceptions() {
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

int main( void ) {
	TITLE("Assignements");
	test_assignements();

	TITLE("Copies");
	test_copies();

	TITLE("Exceptions");
	test_exceptions();
}
