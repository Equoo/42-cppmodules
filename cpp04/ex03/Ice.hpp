#pragma once

#include "AMateria.hpp"
#include <string>

class Ice : public AMateria  {
public:
	Ice();
	Ice(const Ice &other);
	Ice	&operator=(const Ice &other);
	~Ice();

	void	use(ICharacter &target) const;
	Ice 	*clone() const;
};

