#pragma once

#include <string>

class ScalarConverter {
   public:
	static void convert(const std::string &value);

   private:
	static void print_impossible();
};
