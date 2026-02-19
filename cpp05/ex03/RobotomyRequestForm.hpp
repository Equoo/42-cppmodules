#pragma once

#include <stdint.h>

#include <string>

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
   public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &other);
	virtual ~RobotomyRequestForm();

	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

	void execute(Bureaucrat const &person) const;
};
