#pragma once

#include <string>

class AAnimal  {
public:
	virtual ~AAnimal();

	virtual void	makeSound() const = 0;

	virtual std::string	getType() const;

protected:
	std::string	type;
};

