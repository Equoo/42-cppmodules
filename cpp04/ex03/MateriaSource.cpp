
#include "MateriaSource.hpp"

#include <cstddef>
#include <cstring>
#include <string>

#include "log.hpp"

using std::string;

MateriaSource::MateriaSource() {
	std::memset(this->materials, 0, sizeof(AMateria *) * materials_size);
	PRINTLN(BG_C_BLUE, "MateriaSource default construct", RESET);
}
MateriaSource::MateriaSource(const MateriaSource &other) {
	std::memcpy(this->materials, other.materials, sizeof(AMateria *) * materials_size);
	PRINTLN(BG_C_BLUE, "MateriaSource copy construct", RESET);
}
MateriaSource	&MateriaSource::operator=(const MateriaSource &other) {
	PRINTLN(BG_C_BLUE, "MateriaSource assignement", RESET);
	if (this != &other) {
		std::memcpy(this->materials, other.materials, sizeof(AMateria *) * materials_size);
	}
	return (*this);
}
MateriaSource::~MateriaSource() {
	PRINTLN(BG_C_BLUE, "MateriaSource destruct", RESET);
	for (int i = 0; i < materials_size; i++) {
		if (materials[i]) {
			delete materials[i];
		}
	}
}

void MateriaSource::learnMateria(AMateria *m) {
	for (int i = 0; i < materials_size; i++) {
		if (!materials[i]) {
			PRINTLN(BG_C_BLUE, "Learn Materia ", *m, " at slot ", i, RESET);
			materials[i] = m;
			return;
		}
	}
	PRINTLN(BG_C_BLUE, "Learn Materia ", *m, " failed: slots full.", RESET);
	delete m;
}

AMateria* MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < materials_size; i++) {
		if (materials[i] && materials[i]->getType() == type) {
			PRINTLN(BG_C_BLUE, "Create Materia of type ", type, " from slot ", i, RESET);
			return (materials[i]->clone());
		}
	}
	PRINTLN(BG_C_BLUE, "Create Materia of type ", type, " failed: not found.", RESET);
	return (NULL);
}
