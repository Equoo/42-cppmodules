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
	virtual int	getID() const;

	virtual AMateria *clone() const = 0;
	virtual void	use(ICharacter &target) const = 0;

protected:
	static int	construct_count;

	std::string	type;
	int			id;
};

std::ostream&	operator<<(std::ostream& stream, const AMateria& obj);

