#pragma once

#include "AForm.hpp"
#include <stdint.h>
#include <stdexcept>
#include <string>

class ShrubberyCreationForm : public AForm {
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	virtual ~ShrubberyCreationForm();

	ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &other);

	void	toExecute(Bureaucrat &person);
};

