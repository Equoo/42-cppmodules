#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cstddef>
#include <list>
#include <vector>

class PmergeMe {
  public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

	void run(int argc, char **argv);

  private:
	std::vector< int > _vecInput;
	std::list< int > _lstInput;

	void parseArguments(int argc, char **argv);
	void printVector(const char *label, const std::vector< int > &seq) const;

	template < typename Iterator >
	bool isSorted(Iterator first, Iterator last) {
		if (first == last)
			return true;
		Iterator next = first;
		while (++next != last) {
			if (*next < *first)
				return false;
			++first;
		}
		return true;
	}

	void fordJohnsonSortVector(std::vector< int > &arr);
	std::vector< size_t > jacobsthalInsertionOrder(size_t n) const;

	void fordJohnsonSortList(std::list< int > &lst);
};

#endif
