#pragma once

#include <string>

class Brain  {
public:
	Brain();
	Brain(const Brain &other);
	virtual ~Brain();

	Brain	&operator=(const Brain &other);

protected:
	std::string	ideas[100];
};

