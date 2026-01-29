
#include "Character.hpp"
#include "AMateria.hpp"

#include <cstring>
#include <string>

using std::string;

Character::Character() {
	this->name = "";
	std::memset(this->inventory, 0, sizeof(AMateria *) * inventory_size);
}
Character::Character(const string &name) {
	this->name = name;
	std::memset(this->inventory, 0, sizeof(AMateria *) * inventory_size);
}
Character::Character(const Character &other) {
	this->name = other.name;
	std::memcpy(this->inventory, other.inventory, sizeof(AMateria *) * inventory_size);
}
Character	&Character::operator=(const Character &other) {
	if (this != &other) {
		this->name = other.name;
		std::memcpy(this->inventory, other.inventory, sizeof(AMateria *) * inventory_size);
	}
	return (*this);
}
Character::~Character() {}


std::string const &Character::getName() const {
	return (name);
}

void Character::equip(AMateria* m) {
	for (int i = 0; i < inventory_size; i++) {
		if (!inventory[i])
			inventory[i] = m;
	}
}

void Character::unequip(int idx) {
	if (inventory[idx]) {
		inventory[idx] = 0;
	}
}

void Character::use(int idx, ICharacter& target) {
	if (inventory[idx]) {
		inventory[idx]->use(target);
	}
}

