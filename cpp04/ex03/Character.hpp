
#pragma once

#include "ICharacter.hpp"

class Character : public ICharacter {
public:
	Character();
	Character(const std::string &name);
	Character(const Character &other);
	Character &operator=(const Character &other);
	~Character();

	std::string const &getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);

private:
	static const int	inventory_size = 4;

	std::string	name;
	AMateria	*inventory[inventory_size];
};
