#include "Weapon.hpp"

Weapon::Weapon(const Weapon &copy)
{
	type = copy.getType();
}

Weapon::Weapon(std::string type)
{
	this->type = type;
}


std::string Weapon::getType() const
{
	return type;
}

void Weapon::setType(std::string str)
{
	type = str;
}
