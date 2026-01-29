
#include "MateriaSource.hpp"

#include <cstddef>
#include <cstring>
#include <string>

using std::string;

MateriaSource::MateriaSource() {
	std::memset(this->materials, 0, sizeof(AMateria *) * materials_size);
}
MateriaSource::MateriaSource(const MateriaSource &other) {
	std::memcpy(this->materials, other.materials, sizeof(AMateria *) * materials_size);
}
MateriaSource	&MateriaSource::operator=(const MateriaSource &other) {
	if (this != &other) {
		std::memcpy(this->materials, other.materials, sizeof(AMateria *) * materials_size);
	}
	return (*this);
}
MateriaSource::~MateriaSource() {}

void MateriaSource::learnMateria(AMateria *m) {
	for (int i = 0; i < materials_size; i++) {
		if (!materials[i])
			materials[i] = m->clone();
	}
}

AMateria* MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < materials_size; i++) {
		if (materials[i] && materials[i]->getType() == type)
			return (materials[i]->clone());
	}
	return (NULL);
}
