#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <ostream>
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), FragTrap("Default"), ScavTrap("Default"), name("Default") {
	cout << "DiamondTrap " << name << " default constructor." << endl;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), name(name) {
	cout << "DiamondTrap " << name << " constructor(name: " << name << ")." << endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other.name + "_clap_name"), FragTrap(other.name), ScavTrap(other.name), name(other.name) {
	cout << "DiamondTrap " << name << " copy constructor." << endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
	if (this != &other) {
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	cout << "DiamondTrap Assignment Operator Called." << endl;

	return (*this);
}

DiamondTrap::~DiamondTrap() {
	cout << "DiamondTrap " << name << " destructed." << endl;
}

void DiamondTrap::whoAmI() {
	cout << "DiamondTrap name: " << name << "; ClapTrap name: " << ClapTrap::name << "." << endl;
}
