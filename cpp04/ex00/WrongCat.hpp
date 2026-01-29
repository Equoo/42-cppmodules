#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
	WrongCat();
	WrongCat(const WrongCat &other);
	~WrongCat();

	WrongCat	&operator=(const WrongCat &other);

	virtual void	makeSound() const;
};

