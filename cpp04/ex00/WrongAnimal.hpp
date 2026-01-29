#pragma once

#include <string>

class WrongAnimal  {
public:
	WrongAnimal();
	WrongAnimal(const std::string &type);
	WrongAnimal(const WrongAnimal &other);
	virtual ~WrongAnimal();

	WrongAnimal	&operator=(const WrongAnimal &other);

	void	makeSound() const;

	std::string	getType() const;

protected:
	std::string	type;
};

