#pragma once

#include <string>

class ICharacter;

class AMateria  {
public:
	AMateria();
	AMateria(std::string const &type);
	AMateria(const AMateria &other);
	AMateria &operator=(const AMateria &other);
	virtual ~AMateria();

	virtual std::string	getType() const;

	virtual AMateria *clone() const = 0;
	virtual void	use(ICharacter &target) const = 0;

protected:
	std::string	type;
};

