#include "ScalarConverter.hpp"

#include <cerrno>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <istream>
#include <limits>
#include <sstream>
#include <string>

#include "log.hpp"
using std::string;

static string lower_string(const string &_str) {
	string str = _str;

	for (size_t j = 0; j < str.size(); ++j) {
		str[j] = std::tolower(str[j]);
	}
	return str;
}

int ex10(double x) {
	if (x == 0.0) return 0;
	return static_cast<int>(std::floor(std::log10(std::fabs(x))));
}

double round_to(double value, int precision) {
	if (ex10(value) >= precision) return round(value);
	double factor = std::pow(10.0, precision - ex10(value));
	return round(value * factor) / factor;
}

string get_precision_str(double d) {
	return ((floor(d) == round_to(d, 5) || ceil(d) == round_to(d, 5)) && ex10(d) < 6
				? ".0"
				: "");
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
	stream >> buf;

	if (buf != "" && buf != "f") {
		print_impossible();
		return;
	}

	if (stream.fail()) {
		if (value.length() == 1)
			d = value[0];
		else if (lval == "nan" || lval == "nanf")
			d = std::numeric_limits<double>::quiet_NaN();
		else if (lval == "inf" || lval == "inff")
			d = std::numeric_limits<double>::infinity();
		else if (lval == "-inf" || lval == "-inff")
			d = -std::numeric_limits<double>::infinity();
		// else {
		// 	print_impossible();
		// 	return;
		// }
	}

	if (errno == ERANGE) {
		if (d < 0.f)
			d = -std::numeric_limits<double>::infinity();
		else
			d = std::numeric_limits<double>::infinity();
	}

	c = d;
	if (std::isprint(static_cast<unsigned char>(c)) &&
		static_cast<double>(c) - d == 0)
		PRINTLN("char: '", c, "'");
	else
		PRINTLN("char: impossible");

	i = d;
	if (static_cast<double>(i) - d != 0)
		PRINTLN("int: impossible");
	else
		PRINTLN("int: ", i);

	f = d;
	PRINTLN("float: ", f, get_precision_str(f), "f");
	PRINTLN("double: ", d, get_precision_str(d));
}
