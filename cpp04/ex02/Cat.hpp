#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal  {
public:
	Cat();
	Cat(const Cat &other);
	~Cat();

	Cat	&operator=(const Cat &other);

	virtual void	makeSound() const;

private:
	Brain	*brain;
};

