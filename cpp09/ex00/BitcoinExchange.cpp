
#include "BitcoinExchange.hpp"
#include <cctype>
#include <cstddef>
#include <cstring>
#include <ctime>
#include <exception>
#include <fstream>
#include <iostream>
#include <map>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <string>

static std::vector<std::string> split(const std::string& s, const std::string& delimiter) {
    std::vector<std::string> tokens;
    size_t start = 0;
    size_t end = s.find(delimiter);
    while (end != std::string::npos) {
        tokens.push_back(s.substr(start, end - start));
        start = end + delimiter.length();
        end = s.find(delimiter, start);
    }
    tokens.push_back(s.substr(start));
    return tokens;
}

static std::string trunc_space(const std::string &str) {
	std::string input = str;
	size_t	i = 0;

    while (std::isspace(str[i])) {
        input.erase(0, 1);
		i++;
    }

	i = str.length() - 1;
    while (std::isspace(str[i])) {
        input.erase(input.length() - 1, 1);
		i--;
    }
	return input;
}

BitcoinExchange::BitcoinExchange() : _data() {};
BitcoinExchange::BitcoinExchange(BitcoinExchange &other) : _data(other._data) {}
BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange &other) {
    if (this == &other)
        return (other);
    _data = other._data;
    return (*this);
}
BitcoinExchange::~BitcoinExchange() {}

std::runtime_error BitcoinExchange::parsingError(int line, const std::string &msg) {
	std::ostringstream stream;
	stream << line;

	return std::runtime_error("(line: " + stream.str() + ") " + msg);
}

void BitcoinExchange::parseHeaders(std::ifstream &file, const std::string &sep, const std::string &first, const std::string &second) {
	std::string str_line;

	if (!std::getline(file, str_line)) {
		throw parsingError(1, "file empty");
	}

	std::vector<std::string> keys = split(str_line, sep);
	if (keys.size() != 2)
		throw parsingError(1, "bad input => " + str_line);

	if (trunc_space(keys[0]) != first)
		throw parsingError(1, "wrong first key");

	if (trunc_space(keys[1]) != second)
		throw parsingError(1, "wrong second key");
}

bool BitcoinExchange::parseLine(std::ifstream &file, const std::string &sep, t_line &line, size_t &line_count)
{
	std::string str_line;

	if (!std::getline(file, str_line)) {
		return false;
	}
	line_count++;

	std::vector<std::string> values = split(str_line, sep);
	if (values.size() != 2)
		throw parsingError(line_count, "bad input => " + str_line);

	struct tm tmStruct;
	std::memset(&tmStruct, 0, sizeof(tmStruct));

	if (strptime(values[0].c_str(), "%Y-%m-%d", &tmStruct) == NULL)
		throw parsingError(line_count, "invalid date format => " + values[0]);
	line.str_date = trunc_space(values[0]);
	line.date = std::mktime(&tmStruct);

    std::istringstream ss(values[1]);
    ss >> line.value;
	if (ss.fail()) {
		throw parsingError(line_count, "not a number.");
	}

	std::string	trailing;
	ss >> trailing;
	const char *c = trailing.c_str();
	while (*c) {
		if (!std::isspace(*c)) {
			throw parsingError(line_count, "not a number.");
		}
		c++;
	}

	if (line.value < 0) {
		throw parsingError(line_count, "not a positive number.");
	}

    return true;
}

void BitcoinExchange::loadData() {
    std::string filename = "data.csv";
	std::ifstream file;
	t_line	line;
	size_t	line_count = 1;

	try {
		file.open(filename.c_str());
		if (file.fail())
			throw std::runtime_error(std::strerror(errno));

		parseHeaders(file, ",", "date", "exchange_rate");

		while (parseLine(file, ",", line, line_count)) {
			_data[line.date] = line.value;
		}
	} catch (std::exception &e) {
		std::cout << "Error: while loading data.csv: " << e.what() << std::endl;
	}
	file.close();
    return;
}

void BitcoinExchange::exchange(const std::string &filename) const {
	t_line	line;
	size_t	line_count = 1;
	std::ifstream file;

	file.open(filename.c_str());
	if (file.fail())
		throw std::runtime_error(std::strerror(errno));

	try { parseHeaders(file, "|", "date", "value"); }
    catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	while (true) {
		try {
			if (parseLine(file, "|", line, line_count)) {
				if (line.value > 1000) {
					throw parsingError(line_count, "too large number.");
				}

				std::map<std::time_t, float>::const_iterator data_value
					= _data.upper_bound(line.date);
				if (data_value == _data.begin()) {
					data_value = _data.end();
				}
				else {
					--data_value;
				}

				if (data_value != _data.end()) {
					std::cout
						<< line.str_date
						<< " => "
						<< line.value
						<< " = "
						<< (data_value->second * line.value)
						<< std::endl;
				}
			} else {
				break;
			}
		} catch (std::exception &e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	file.close();
    return;
}
