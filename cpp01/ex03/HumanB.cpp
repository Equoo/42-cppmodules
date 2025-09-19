#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanB::HumanB(const HumanB &copy) {
	name = copy.getName();
	weapon = copy.getWeapon();
}

HumanB::HumanB(std::string name) {
	this->name = name;
	this->weapon = NULL;
}


std::string HumanB::getName() const {
	return name;
}

Weapon *HumanB::getWeapon() const {
	return weapon;
}

void HumanB::setWeapon(Weapon &weapon) {
	this->weapon = &weapon;
}


void HumanB::attack() const {
	if (weapon)
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	else
		std::cout << name << " doesn't have weapon.";
}
