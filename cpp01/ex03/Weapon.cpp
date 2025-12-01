#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type) {}

std::string Weapon::getType() const
{
	return type;
}

void Weapon::setType(std::string str)
{
	type = str;
}
