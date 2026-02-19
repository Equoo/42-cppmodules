#pragma once

#include <stdint.h>

#include <stdexcept>
#include <string>

class Bureaucrat;

class AForm {
   public:
	AForm();
	AForm(const std::string &name, uint8_t grade_tosign, uint8_t grade_toexec);
	AForm(const AForm &other);
	virtual ~AForm();

	AForm &operator=(const AForm &other);

	void beSigned(Bureaucrat const &person);
	virtual void execute(Bureaucrat const &person) const = 0;

	std::string getName() const;
	std::string getTarget() const;
	uint8_t getGradeToSign() const;
	uint8_t getGradeToExec() const;
	bool getSigned() const;

	static const std::invalid_argument GradeTooHighException;
	static const std::invalid_argument GradeTooLowException;
	static const std::invalid_argument AlreadySignedException;
	static const std::invalid_argument NotSignedException;

   private:
	const std::string _name;
	const uint8_t _grade_tosign;
	const uint8_t _grade_toexec;
	bool _signed;

	void checkGrade(uint8_t value) const;

   protected:
	std::string _target;

	void checkExecute(Bureaucrat const &person) const;
};

std::ostream &operator<<(std::ostream &stream, const AForm &obj);
