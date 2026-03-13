
#include "Serializer.hpp"
#include "Data.hpp"
#include "log.hpp"
#include <stdint.h>
#include <cstdio>
#include <iostream>
#include <string>

using std::string;

int main() {
	Data data = {14, true};

	uintptr_t raw = Serializer::serialize(&data);
	Data *ptr = Serializer::deserialize(raw);

	PRINTLN("Original: limit(", data.limit, ") is_heavy(", data.is_heavy, ")");
	PRINTLN("PTR: limit(", ptr->limit, ") is_heavy(", ptr->is_heavy, ")");
	PRINTLN("ptr: ", &data, " raw: ", raw);

	return (0);
}
