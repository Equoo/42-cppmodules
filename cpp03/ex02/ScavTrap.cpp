#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <ostream>
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

ScavTrap::ScavTrap() : ClapTrap() {
	cout << "ScavTrap " << name << " default constructor." << endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	cout << "ScavTrap " << name << " constructor(name: " << name << ")." << endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
	cout << "ScavTrap " << name << " copy constructor." << endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
	if (this != &other) {
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	cout << "ScavTrap Assignment Operator Called." << endl;

	return (*this);
}

ScavTrap::~ScavTrap() {
	cout << "ScavTrap " << name << " destructed." << endl;
}

void	ScavTrap::attack(const string &target) {
	if (energyPoints <= 0) {
		cout << "ScavTrap " << name << " attacks failed: not enough energy points." << endl;
		return;
	}
	if (hitPoints <= 0) {
		cout << "ScavTrap " << name << " attacks failed: not enough hitPoints." << endl;
		return;
	}
	cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << endl;
	energyPoints--;
}

void ScavTrap::guardGate() {
	cout << "ScavTrap " << name << " is now in Gate keeper mode." << endl;
}
