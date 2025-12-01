#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include "Weapon.hpp"

class HumanB
{
public:
	HumanB(std::string name);
	
public:
	void		attack() const;

public:
	std::string getName() const;
	Weapon 		*getWeapon() const;
	void 		setWeapon(Weapon &weapon);

private:
	Weapon		*weapon;
	std::string	name;
};

#endif
