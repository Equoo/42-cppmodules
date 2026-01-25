#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <ostream>
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

FragTrap::FragTrap() : ClapTrap() {
	cout << "FragTrap " << name << " default constructor." << endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
	hitPoints =
	energyPoints = 100;
	attackDamage = 30;
	cout << "FragTrap " << name << " constructor(name: " << name << ")." << endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
	cout << "FragTrap " << name << " copy constructor." << endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
	if (this != &other) {
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	cout << "FragTrap Assignment Operator Called." << endl;

	return (*this);
}

FragTrap::~FragTrap() {
	cout << "FragTrap " << name << " destructed." << endl;
}

void FragTrap::highFivesGuys() {
	cout << "Yeah high fives ^^" << endl;
}
