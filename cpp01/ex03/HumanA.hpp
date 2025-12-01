#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include "Weapon.hpp"

class HumanA
{
public:
	HumanA(std::string name, Weapon &weapon);
	
public:
	void		attack() const;

public:
	std::string getName() const;
	Weapon 		&getWeapon() const;
	void 		setWeapon(Weapon &weapon);

private:
	Weapon		&weapon;
	std::string	name;
};

#endif
