#pragma once

#include <stdint.h>

#include "Data.hpp"

class Serializer {
   public:
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);

   private:
	Serializer();
	Serializer(Serializer &other);
	~Serializer();
	Serializer &operator=(Serializer &other);
};
