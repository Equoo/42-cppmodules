#pragma once

#include <string>

class ScalarConverter {
   public:
	static void convert(const std::string &value);

   private:
	ScalarConverter();
	ScalarConverter(ScalarConverter &other);
	~ScalarConverter();
	ScalarConverter &operator=(ScalarConverter &other);

	static void print_impossible();
	static std::string get_precision_str(double d);
};
