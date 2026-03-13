#include "ScalarConverter.hpp"

#include <stdint.h>

#include <cctype>
#include <cerrno>
#include <cmath>
#include <cstring>
#include <iostream>
#include <istream>
#include <limits>
#include <sstream>
#include <string>

#include "utils.hpp"
#include "log.hpp"

using std::string;

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(ScalarConverter &other) { (void)other; }
ScalarConverter::~ScalarConverter() {}
ScalarConverter &ScalarConverter::operator=(ScalarConverter &other) { (void)other; return *this; }

string ScalarConverter::get_precision_str(double d) {
	return (
		(floor(d) == round_to(d, 5) || ceil(d) == round_to(d, 5))
		&& ex10(d) < 6 ? ".0" : "");
}

void ScalarConverter::print_impossible() {
	PRINTLN("char: impossible");
	PRINTLN("int: impossible");
	PRINTLN("float: impossible");
	PRINTLN("double: impossible");
}

void ScalarConverter::convert(const string &value) {
	string lval = lower_string(value);
	std::istringstream stream(lval);
	string buf;
	char c = 0;
	int i = 0;
	float f = 0;
	double d = 0;

	stream >> d;

	if (stream.fail()) {
		if (value.length() == 3 && value[0] == '\'' && value[2] == '\'')
			d = value[1];
		else if (lval == "nan" || lval == "nanf")
			d = std::numeric_limits<double>::quiet_NaN();
		else if (lval == "+inf" || lval == "+inff")
			d = std::numeric_limits<double>::infinity();
		else if (lval == "-inf" || lval == "-inff")
			d = -std::numeric_limits<double>::infinity();
		else {
			print_impossible();
			return;
		}
	}

	stream >> buf;
	if ((buf != "" && buf != "f") ||
		(buf == "f" && value.find(".") == std::string::npos)) {
		print_impossible();
		return;
	}

	if (errno == ERANGE) {
		if (d < 0.f)
			d = -std::numeric_limits<double>::infinity();
		else
			d = std::numeric_limits<double>::infinity();
	}

	if (lval == "nan" || lval == "nanf") {
		PRINTLN("char: impossible");
		PRINTLN("int: impossible");
	} else {
		c = d;
		if (std::isprint(static_cast<unsigned char>(c)) &&
			static_cast<double>(c) - d == 0)
			PRINTLN("char: '", c, "'");
		else if (static_cast<double>(c) - static_cast<int64_t>(d) != 0 || d < 0 ||
				 d > 127)
			PRINTLN("char: impossible");
		else
			PRINTLN("char: Non displayable");

		i = d;
		if (d > static_cast<double>(std::numeric_limits<int>::max()) ||
			d < static_cast<double>(std::numeric_limits<int>::min()))
			PRINTLN("int: impossible");
		else
			PRINTLN("int: ", i);
	}

	f = d;
	const char *inff_symb = f == std::numeric_limits<float>::infinity() ? "+" : "";
	const char *inf_symb = d == std::numeric_limits<double>::infinity() ? "+" : "";
	PRINTLN("float: ", inff_symb, f, get_precision_str(f), "f");
	PRINTLN("double: ", inf_symb, d, get_precision_str(d));
}
