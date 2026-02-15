#pragma once

#include <stdint.h>
#include <stdexcept>
#include <string>

class Form;

class Bureaucrat  {
public:
	Bureaucrat();
	Bureaucrat(const std::string &name, uint8_t grade);
	Bureaucrat(const Bureaucrat &other);
	~Bureaucrat();

	Bureaucrat	&operator=(const Bureaucrat &other);

	void	signForm(Form &form);

	void	gradeIncrement();
	void	gradeDecrement();

	uint8_t	getGrade() const;
	void	setGrade(uint8_t grade);
	std::string	getName() const;

	static const std::invalid_argument GradeTooHighException;
	static const std::invalid_argument GradeTooLowException;

private:
	const std::string	name;
	uint8_t				grade;
};

std::ostream&	operator<<(std::ostream& stream, const Bureaucrat& obj);
