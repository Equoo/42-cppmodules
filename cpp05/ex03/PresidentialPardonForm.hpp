#pragma once

#include <stdint.h>

#include <string>

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
   public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	virtual ~PresidentialPardonForm();

	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

	void execute(Bureaucrat const &person) const;
};
