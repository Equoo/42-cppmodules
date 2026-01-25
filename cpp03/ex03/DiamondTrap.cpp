#include "DiamondTrap.hpp"
#include <ostream>
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), name(name) {
	cout << "DiamondTrap " << name << " created." << endl;
}
DiamondTrap::~DiamondTrap() {
	cout << "DiamondTrap " << name << " destructed." << endl;
}

void DiamondTrap::whoAmI() {
	cout << "DiamondTrap name: " << name << "; ClapTrap name: " << ClapTrap::name << ".";
}
