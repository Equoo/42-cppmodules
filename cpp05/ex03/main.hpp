
#pragma once

#include <iostream>
#include <typeinfo>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "log.hpp"

template <typename T>
void test_one_copy(const T &a) {
	PRINTLN("# A = ", a);

	T b = T(a);
	PRINTLN("# B = ", b);
}

template <typename T>
void test_one_assignement(const T &a) {
	T b = T();

	PRINTLN("# B = ", b);
	PRINTLN("# Assignement of ", a);
	b = a;
	PRINTLN("# B = ", b);
}

template <typename T>
void test_execute_form(T form) {
	Bureaucrat a("Singer", 1);
	Bureaucrat b("Singer", 150);

	a.executeForm(form);
	a.signForm(form);
	b.executeForm(form);
	a.executeForm(form);
}
