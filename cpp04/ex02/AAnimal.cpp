#include "log.hpp"
#include "AAnimal.hpp"
#include <string>

using std::string;

AAnimal::~AAnimal() {}

string	AAnimal::getType() const { return (type); }

