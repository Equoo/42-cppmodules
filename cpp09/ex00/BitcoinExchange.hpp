
#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <cstddef>
# include <ctime>
# include <fstream>
# include <map>
# include <string>

typedef struct {
	std::time_t	date;
	std::string	str_date;
	float		value;
}				t_line;

class BitcoinExchange {
public:
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange &other);
	BitcoinExchange &operator=(BitcoinExchange &other);
	~BitcoinExchange();

	void loadData();
	void exchange(const std::string &filename) const;

private:
	std::map<std::time_t, float> _data;

	static void parseHeaders(std::ifstream &file, const std::string &sep, const std::string &first, const std::string &second);
	static bool parseLine(std::ifstream &file, const std::string &sep, t_line &line,  size_t &line_count);

	static std::runtime_error parsingError(int line, const std::string &msg);
};

#endif
