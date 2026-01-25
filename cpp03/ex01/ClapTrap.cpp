#include "ClapTrap.hpp"
#include <ostream>
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;


ClapTrap::ClapTrap() : name("DefaultName"), hitPoints(10), energyPoints(10), attackDamage(0) {
	cout << "ClapTrap " << name << " default constructor." << endl;
}

ClapTrap::ClapTrap(const std::string &name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
	cout << "ClapTrap " << name << " constructor(name: " << name << ")." << endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) :
	name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage) {
	cout << "ClapTrap " << name << " copy constructor." << endl;
}

ClapTrap::~ClapTrap() {
	cout << "ClapTrap " << name << " destructed." << endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	if (this != &other) {
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	cout << "ClapTrap Assignment Operator Called." << endl;

	return (*this);
}

std::ostream&	operator<<(std::ostream& stream, const ClapTrap& obj) {
	return (stream << "ClapTrap[" << obj.getName() << "]");
}

string	ClapTrap::getName() const { return (name); }
int	ClapTrap::getHitPoints() const { return (hitPoints); }
int	ClapTrap::getEnergyPoints() const { return (energyPoints); }
int	ClapTrap::getAttackDamage() const { return (attackDamage); }
void	ClapTrap::setAttackDamage(int amount) { attackDamage = amount; }

void	ClapTrap::attack(const string &target) {
	if (energyPoints <= 0) {
		cout << "ClapTrap " << name << " attacks failed: not enough energy points." << endl;
		return;
	}
	if (hitPoints <= 0) {
		cout << "ClapTrap " << name << " attacks failed: not enough hitPoints." << endl;
		return;
	}
	cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << endl;
	energyPoints--;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (energyPoints <= 0) {
		cout << "ClapTrap " << name << " repair failed: not enough energy points." << endl;
		return;
	}
	if (hitPoints <= 0) {
		cout << "ClapTrap " << name << " repair failed: not enough hitPoints." << endl;
		return;
	}
	cout << "ClapTrap " << name << " repaired of " << amount << " hitPoints." << endl;
	hitPoints += amount;
	energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (hitPoints <= 0) {
		cout << "ClapTrap " << name << " is already dead, why do you attack him ??" << endl;
		return;
	}
	cout << "ClapTrap " << name << " taked " << amount << " damages" << endl;
	hitPoints -= amount;
}


