#include "HumanA.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon) : weapon(weapon), name(name) {}

std::string HumanA::getName() const {
	return name;
}

Weapon &HumanA::getWeapon() const {
	return weapon;
}

void HumanA::setWeapon(Weapon &weapon) {
	this->weapon = weapon;
}

void HumanA::attack() const {
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
