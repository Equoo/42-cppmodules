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
	std::vector< size_t > order;

	size_t prev = 1;
	size_t curr = 3;
	while (prev < n) {
		size_t higher_bound = std::min(curr, n);

		for (size_t i = higher_bound; i >= prev + 1; i--) {
			order.push_back(i - 1);
		}

		size_t next = curr + 2 * prev;
		prev = curr;
		curr = next;
	}

	return order;
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

	std::vector< size_t > order = jacobsthalInsertionOrder(sortedPairs.size());

	for (size_t i = 0; i < order.size(); i++) {
		int loser = sortedPairs[order[i]].second;
		int winner = sortedPairs[order[i]].first;

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

	bool hasStraggler = (n % 2 == 1);
	int straggler = lst.back();
	if (hasStraggler) {
		lst.pop_back();
		n -= 1;
	}

	std::list< std::pair< int, int > > pairs;
	std::list< int >::iterator it = lst.begin();
	while (it != lst.end()) {
		int a = *it;
		++it;
		if (it == lst.end())
			break;
		int b = *it;
		++it;
		if (a > b)
			pairs.push_back(std::pair< int, int >(a, b));
		else
			pairs.push_back(std::pair< int, int >(b, a));
	}

	std::list< int > winners;
	for (std::list< std::pair< int, int > >::iterator pit = pairs.begin();
	     pit != pairs.end(); ++pit) {
		winners.push_back(pit->first);
	}
	fordJohnsonSortList(winners);

	std::list< bool > used(pairs.size(), false);
	std::list< std::pair< int, int > > sortedPairs;
	std::list< int > chain;

	for (std::list< int >::iterator wit = winners.begin(); wit != winners.end();
	     ++wit) {
		std::list< std::pair< int, int > >::iterator pit = pairs.begin();
		std::list< bool >::iterator uit = used.begin();
		for (; pit != pairs.end(); ++pit, ++uit) {
			if (!*uit && pit->first == *wit) {
				sortedPairs.push_back(*pit);
				chain.push_back(pit->first);
				*uit = true;
				break;
			}
		}
	}

	if (!sortedPairs.empty())
		chain.push_front(sortedPairs.begin()->second);

	std::vector< size_t > order = jacobsthalInsertionOrder(sortedPairs.size());

	for (size_t i = 0; i < order.size(); i++) {
		std::list< std::pair< int, int > >::iterator pit = sortedPairs.begin();
		std::advance(pit, order[i]);
		int loser = pit->second;
		int winner = pit->first;
		std::list< int >::iterator winnerIt =
			std::find(chain.begin(), chain.end(), winner);
		std::list< int >::iterator pos =
			std::lower_bound(chain.begin(), winnerIt, loser);
		chain.insert(pos, loser);
	}

	if (hasStraggler) {
		std::list< int >::iterator pos =
			std::lower_bound(chain.begin(), chain.end(), straggler);
		chain.insert(pos, straggler);
	}

	lst = chain;
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
}
