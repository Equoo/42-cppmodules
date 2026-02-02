
#include "Character.hpp"
#include "AMateria.hpp"
#include "log.hpp"

#include <cstring>
#include <string>

using std::string;

Character::Character() : name("") {
	std::memset(this->inventory, 0, sizeof(AMateria *) * inventory_size);
	PRINTLN(BG_C_GREEN, "Character default construct", RESET);
}
Character::Character(const string &name) : name(name) {
	std::memset(this->inventory, 0, sizeof(AMateria *) * inventory_size);
	PRINTLN(BG_C_GREEN, "Character construct: ", name, RESET);
}
Character::Character(const Character &other) : name(other.name) {
	std::memcpy(this->inventory, other.inventory, sizeof(AMateria *) * inventory_size);
	PRINTLN(BG_C_GREEN, "Character copy construct: ", name, RESET);
}
Character	&Character::operator=(const Character &other) {
	if (this != &other) {
		this->name = other.name;
		std::memcpy(this->inventory, other.inventory, sizeof(AMateria *) * inventory_size);
	}
	return (*this);
}
Character::~Character() {
	PRINTLN(BG_C_GREEN, "Character destruct: ", name, RESET);
	for (int i = 0; i < inventory_size; i++) {
		if (inventory[i]) {
			delete inventory[i];
		}
	}
}


std::string const &Character::getName() const {
	return (name);
}

void Character::equip(AMateria* m) {
	for (int i = 0; i < inventory_size; i++) {
		if (inventory[i] == m) {
			PRINTLN(BG_C_GREEN, "Character failed to equip ", *m, ": already equiped", RESET);
			delete m;
			return;
		}
	}

	for (int i = 0; i < inventory_size; i++) {
		if (!inventory[i]) {
			PRINTLN(BG_C_GREEN, "Character equip ", *m, " at ", i, RESET);
			inventory[i] = m;
			return;
		}
	}
	PRINTLN(BG_C_GREEN, "Character failed to equip ", *m, ": slots full", RESET);
	delete m;
}

void Character::unequip(int idx) {
	if (idx >= inventory_size) {
		PRINTLN(BG_C_GREEN, "Character failed to unequip ", idx, ": inventory size is ", inventory_size, RESET);
		return;
	}
	if (inventory[idx]) {
		PRINTLN(BG_C_GREEN, "Character unequip ", idx, ": ", *inventory[idx], RESET);
		delete inventory[idx];
		inventory[idx] = 0;
	} else {
		PRINTLN(BG_C_GREEN, "Character failed to unequip ", idx, ": slot empty", RESET);
	}
}

void Character::use(int idx, ICharacter& target) {
	if (idx >= inventory_size) {
		PRINTLN(BG_C_GREEN, "Character failed to use ", idx, ": inventory size is ", inventory_size, RESET);
		return;
	}
	if (inventory[idx]) {
		inventory[idx]->use(target);
	}
	PRINTLN(BG_C_GREEN, "Character failed to use ", idx, ": slot empty", RESET);
}

