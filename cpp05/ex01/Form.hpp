#pragma once

#include "Bureaucrat.hpp"
#include <stdint.h>
#include <stdexcept>
#include <string>

class Bureaucrat;

class Form  {
public:
	Form();
	Form(const std::string &name, uint8_t grade_tosign, uint8_t grade_toexec);
	Form(const Form &other);
	~Form();

	Form	&operator=(const Form &other);

	void	beSigned(Bureaucrat &person);

	std::string	getName() const;
	uint8_t	getGradeToSign() const;
	uint8_t	getGradeToExec() const;
	bool	getSigned() const;

	static const std::invalid_argument GradeTooHighException;
	static const std::invalid_argument GradeTooLowException;

private:
	const std::string	_name;
	const uint8_t		_grade_tosign;
	const uint8_t		_grade_toexec;
	bool				_signed;
	
	void	checkGrade(uint8_t value);
};

std::ostream&	operator<<(std::ostream& stream, const Form& obj);
