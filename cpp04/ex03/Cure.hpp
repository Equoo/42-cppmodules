#pragma once

#include "AMateria.hpp"
#include <string>

class Cure : public AMateria  {
public:
	Cure();
	Cure(const Cure &other);
	Cure &operator=(const Cure &other);
	~Cure();

	void	use(ICharacter &target) const;
	Cure 	*clone() const;
};

