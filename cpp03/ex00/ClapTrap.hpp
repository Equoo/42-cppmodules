#pragma once

#include <ostream>
#include <stdint.h>
#include <string>

class ClapTrap  {
public:
	ClapTrap();
	ClapTrap(const std::string &name);
	ClapTrap(const ClapTrap &other);
	~ClapTrap();

	ClapTrap	&operator=(const ClapTrap &other);

	void			attack(const std::string &target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);

	std::string	getName() const;
	int			getHitPoints() const;
	int			getEnergyPoints() const;
	int			getAttackDamage() const;
	void		setAttackDamage(int amount);

private:
	std::string	name;
	int			hitPoints;
	int			energyPoints;
	int			attackDamage;
};

std::ostream&	operator<<(std::ostream& stream, const ClapTrap& obj);
