#include "PmergeMe.hpp"
#include <algorithm>
#include <climits>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <sys/time.h>
#include <utility>
#include <vector>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
	: _vecInput(other._vecInput), _lstInput(other._lstInput) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other) {
		_vecInput = other._vecInput;
		_lstInput = other._lstInput;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

static bool isValidPositiveNumber(const std::string &token, long &out) {
	if (token.empty())
		return false;

	size_t i = 0;
	if (token[0] == '+')
		i = 1;
	if (i == token.size())
		return false;

	for (size_t j = i; j < token.size(); ++j) {
		if (!std::isdigit(static_cast< unsigned char >(token[j])))
			return false;
	}

	errno = 0;
	char *end = 0;
	long value = std::strtol(token.c_str(), &end, 10);

	if (errno == ERANGE || value > INT_MAX || value <= 0)
		return false;

	out = value;
	return true;
}

void PmergeMe::parseArguments(int argc, char **argv) {
	for (int i = 1; i < argc; ++i) {
		std::string token(argv[i]);
		long value;

		if (!isValidPositiveNumber(token, value))
			throw std::runtime_error("Error");

		_vecInput.push_back(static_cast< int >(value));
		_lstInput.push_back(static_cast< int >(value));
	}

	if (_vecInput.empty())
		throw std::runtime_error("Error");
}

void PmergeMe::printVector(const char *label,
                           const std::vector< int > &seq) const {
	std::cout << label;
	for (size_t i = 0; i < seq.size(); ++i)
		std::cout << seq[i] << " ";
	std::cout << std::endl;
}

std::vector< size_t > PmergeMe::jacobsthalInsertionOrder(size_t n) const {
	return std::vector< size_t >(n);
}

void PmergeMe::fordJohnsonSortVector(std::vector< int > &arr) {
	size_t n = arr.size();
	if (n <= 1)
		return;

	bool hasStraggler = (n % 2 == 1);
	int straggler = arr.back();

	if (hasStraggler) {
		arr.pop_back();
		n -= 1;
	}

	std::vector< std::pair< int, int > > pairs;
	for (size_t i = 0; i + 1 < n; i += 2) {
		int a = arr[i];
		int b = arr[i + 1];

		if (a > b)
			pairs.push_back(std::pair< int, int >(a, b));
		else
			pairs.push_back(std::pair< int, int >(b, a));
	}

	std::vector< int > winners;
	for (std::vector< std::pair< int, int > >::iterator it = pairs.begin();
	     it < pairs.end(); it++) {
		winners.push_back(it->first);
	}
	fordJohnsonSortVector(winners);

	std::vector< bool > used(pairs.size(), false);
	std::vector< std::pair< int, int > > sortedPairs;
	std::vector< int > chain;

	for (size_t i = 0; i < winners.size(); i++) {
		for (size_t j = 0; j < pairs.size(); j++) {
			if (!used[j] && pairs[j].first == winners[i]) {
				sortedPairs.push_back(pairs[j]);
				chain.push_back(pairs[j].first);
				used[j] = true;
				break;
			}
		}
	}

	if (!sortedPairs.empty())
		chain.insert(chain.begin(), sortedPairs[0].second);

	for (size_t i = 1; i < sortedPairs.size(); i++) {
		int loser = sortedPairs[i].second;
		int winner = sortedPairs[i].first;

		std::vector< int >::iterator winnerIt =
			std::find(chain.begin(), chain.end(), winner);
		std::vector< int >::iterator pos =
			std::lower_bound(chain.begin(), winnerIt, loser);
		chain.insert(pos, loser);
	}

	if (hasStraggler) {
		std::vector< int >::iterator pos =
			std::lower_bound(chain.begin(), chain.end(), straggler);
		chain.insert(pos, straggler);
	}

	arr = chain;
}

void PmergeMe::fordJohnsonSortList(std::list< int > &lst) {
	size_t n = lst.size();
	if (n <= 1)
		return;
}

void PmergeMe::run(int argc, char **argv) {
	parseArguments(argc, argv);

	printVector("Before: ", _vecInput);

	std::vector< int > vecCopy(_vecInput);
	std::list< int > lstCopy(_lstInput);

	struct timeval start, end;

	gettimeofday(&start, NULL);
	fordJohnsonSortVector(vecCopy);
	gettimeofday(&end, NULL);
	double vecTime =
		(end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);

	gettimeofday(&start, NULL);
	fordJohnsonSortList(lstCopy);
	gettimeofday(&end, NULL);
	double lstTime =
		(end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);

	printVector("After: ", vecCopy);

	std::cout << "Time to process a range of " << _vecInput.size()
			  << " elements with std::vector : " << vecTime << " us"
			  << std::endl;
	std::cout << "Time to process a range of " << _lstInput.size()
			  << " elements with std::list : " << lstTime << " us" << std::endl;

	// NOTE: DEBUG
	std::cout << "Vector sorted: " << isSorted(vecCopy.begin(), vecCopy.end())
			  << std::endl
			  << "List sorted: " << isSorted(lstCopy.begin(), lstCopy.end())
			  << std::endl;
}
