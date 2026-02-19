#pragma once

#include <stdint.h>

#include <stdexcept>
#include <string>

#include "AForm.hpp"

enum e_form {
	PRESIDENTIAL_PARDON,
	ROBOTOMY_REQUEST,
	SHRUBBERY_CREATION
};

class Intern {
   public:
	Intern();
	Intern(const Intern &other);
	~Intern();

	Intern &operator=(const Intern &other);

	AForm *makeForm(std::string form, const std::string &target) const;

   private:
	static const char *forms[3];
};

std::ostream &operator<<(std::ostream &stream, const Intern &obj);
