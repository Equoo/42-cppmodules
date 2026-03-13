
#include <cmath>
#include <string>

using std::string;

string lower_string(const string &_str) {
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
