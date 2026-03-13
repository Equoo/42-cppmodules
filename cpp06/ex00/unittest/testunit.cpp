

#include <sstream>
#include "../log.hpp"
#include <iostream>
#include <string>
#include <cstdio>
#include <cstddef>

using std::istringstream;
using std::string;

string exec(const char* cmd) {
    string result;

	FILE* pipe = popen(cmd, "r");
    if (!pipe) return "ERROR";

    char buffer[128];
    while (fgets(buffer, sizeof(buffer), pipe) != NULL) {
        result += buffer;
    }
    pclose(pipe);
    return result;
}

int	do_test(string str, string cres, string ires, string fres, string dres) {
	const string result = exec(("./bin \"" + str + "\"").c_str());
	if (result == "ERROR") return -1;

	PRINT("Test(\"", str, "\") - ");
	istringstream stream(result);
	string	line;
	while (std::getline(stream, line)) {
		if (line.find("char: ") != std::string::npos) {
			string value = line.substr(6, line.length() - 6);
			if (value != cres) {
				PRINTLN("char failed, get \"", value, "\" expected \"", cres, "\"");
				return (1);
			}
		}
		else if (line.find("int: ") != std::string::npos) {
			string value = line.substr(5, line.length() - 5);
			if (value != ires) {
				PRINTLN("int failed, get \"", value, "\" expected \"", ires, "\"");
				return (1);
			}
		}
		else if (line.find("float: ") != std::string::npos) {
			string value = line.substr(7, line.length() - 7);
			if (value != fres) {
				PRINTLN("float failed, get \"", value, "\" expected \"", fres, "\"");
				return (1);
			}
		}
		else if (line.find("double: ") != std::string::npos) {
			string value = line.substr(8, line.length() - 8);
			if (value != dres) {
				PRINTLN("double failed, get \"", value, "\" expected \"", dres, "\"");
				return (1);
			}
		}
	}
	PRINTLN("OK");
	return 0;
}

int main() {
	// === INTEGER LITERALS ===
	do_test("0",           "Non displayable", "0",           "0.0f",        "0.0");
	do_test("1",           "Non displayable", "1",           "1.0f",        "1.0");
	do_test("31",          "Non displayable", "31",          "31.0f",       "31.0");
	do_test("32",          "' '",             "32",          "32.0f",       "32.0");
	do_test("33",          "'!'",             "33",          "33.0f",       "33.0");
	do_test("42",          "'*'",             "42",          "42.0f",       "42.0");
	do_test("126",         "'~'",             "126",         "126.0f",      "126.0");
	do_test("127",         "Non displayable", "127",         "127.0f",      "127.0");
	do_test("128",         "impossible",      "128",         "128.0f",      "128.0");
	do_test("-1",          "impossible",      "-1",          "-1.0f",       "-1.0");
	do_test("-42",         "impossible",      "-42",         "-42.0f",      "-42.0");
	do_test("2147483647",  "impossible",      "2147483647",  "2.14748e+09f","2.14748e+09");
	do_test("-2147483648", "impossible",      "-2147483648", "-2.14748e+09f","-2.14748e+09");
	do_test("2147483648",  "impossible",      "impossible",  "2.14748e+09f","2.14748e+09");
	do_test("-2147483649", "impossible",      "impossible",  "-2.14748e+09f","-2.14748e+09");

	// === FLOAT LITERALS ===
	do_test("0.0f",   "Non displayable", "0",   "0.0f",   "0.0");
	do_test("1.0f",   "Non displayable", "1",   "1.0f",   "1.0");
	do_test("42.0f",  "'*'",             "42",  "42.0f",  "42.0");
	do_test("-42.0f", "impossible",      "-42", "-42.0f", "-42.0");
	do_test("4.2f",   "Non displayable", "4",   "4.2f",   "4.2");
	do_test("-4.2f",  "impossible",      "-4",  "-4.2f",  "-4.2");
	do_test("1.5f",   "Non displayable", "1",   "1.5f",   "1.5");
	do_test("nanf",   "impossible",      "impossible", "nanf",  "nan");
	do_test("+inff",  "impossible",      "impossible", "+inff", "+inf");
	do_test("-inff",  "impossible",      "impossible", "-inff", "-inf");

	// === DOUBLE LITERALS ===
	do_test("0.0",    "Non displayable", "0",   "0.0f",   "0.0");
	do_test("1.0",    "Non displayable", "1",   "1.0f",   "1.0");
	do_test("42.0",   "'*'",             "42",  "42.0f",  "42.0");
	do_test("-42.0",  "impossible",      "-42", "-42.0f", "-42.0");
	do_test("4.2",   "Non displayable", "4",   "4.2f",   "4.2");
	do_test("-4.2",   "impossible",      "-4",  "-4.2f",  "-4.2");
	do_test("1.5",    "Non displayable", "1",   "1.5f",   "1.5");
	do_test("nan",    "impossible",      "impossible", "nanf",  "nan");
	do_test("nanf",    "impossible",      "impossible", "nanf",  "nan");
	do_test("+inf",   "impossible",      "impossible", "+inff", "+inf");
	do_test("-inf",   "impossible",      "impossible", "-inff", "-inf");
	do_test("1.8e308","impossible",      "impossible", "impossible", "impossible");
	do_test("-1.8e308","impossible",     "impossible", "impossible", "impossible");
	do_test("1e39",   "impossible",      "impossible", "+inff", "1e+39");

	// === CHAR LITERALS ===
	do_test("'a'", "'a'", "97",  "97.0f",  "97.0");
	do_test("'A'", "'A'", "65",  "65.0f",  "65.0");
	do_test("'z'", "'z'", "122", "122.0f", "122.0");
	do_test("'Z'", "'Z'", "90",  "90.0f",  "90.0");
	do_test("'0'", "'0'", "48",  "48.0f",  "48.0");
	do_test("'*'", "'*'", "42",  "42.0f",  "42.0");
	do_test("'!'", "'!'", "33",  "33.0f",  "33.0");
	do_test("'~'", "'~'", "126", "126.0f", "126.0");
	do_test("' '", "' '", "32",  "32.0f",  "32.0");

	// === INVALID INPUTS ===
	do_test("",        "impossible", "impossible", "impossible", "impossible");
	do_test("abc",     "impossible", "impossible", "impossible", "impossible");
	do_test("42abc",   "impossible", "impossible", "impossible", "impossible");
	do_test("42.0.0",  "impossible", "impossible", "impossible", "impossible");
	do_test("--42",    "impossible", "impossible", "impossible", "impossible");
	do_test("++42",    "impossible", "impossible", "impossible", "impossible");
	do_test("42f",     "impossible", "impossible", "impossible", "impossible");
	do_test("inf",     "impossible", "impossible", "impossible", "impossible");
	do_test("inff",    "impossible", "impossible", "impossible", "impossible");

	return (0);
}


