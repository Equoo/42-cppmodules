#pragma once

#include <stdint.h>
#include <string>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
public:
	DiamondTrap(const std::string &name);
	DiamondTrap(const DiamondTrap &obj);
	~DiamondTrap();

	using	ScavTrap::attack;
	void	whoAmI();

private:
	std::string	name;
	// using	FragTrap::hitPoints;
	// using	ScavTrap::energyPoints;
	// using	FragTrap::attackDamage;
};

