
#include "Span.hpp"
#include <algorithm>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <stdexcept>
#include <vector>

Span::Span() : data() {};
Span::Span(Span &other) : data(other.data) {}
Span &Span::operator=(Span &other) {
	if (this == &other)
		return (other);
	data = other.data;
	return (*this);
}
Span::~Span() {}

void Span::addNumber(int nb) {
	data.push_back(nb);
}

int Span::longestSpan() const {
	if (size() <= 1) {
		throw std::runtime_error("Not enough numbers for shortestSpan");
	}

	int min = *std::min_element(data.begin(), data.end());
	int max = *std::max_element(data.begin(), data.end());

	return (max - min);
}

int Span::shortestSpan() const {
	if (size() <= 1) {
		throw std::runtime_error("Not enough numbers for shortestSpan");
	}

	std::vector<int> dat = data;
	std::sort(dat.begin(), dat.end());

	int min = INT_MAX;
	for (std::size_t i = 1; i < dat.size(); i++)
		min = std::min(min, std::abs(dat[i] - dat[i - 1]));
	return min;
}

const int &Span::operator[](unsigned int n) const {
	if (n >= data.size())
		throw std::out_of_range("Index is out of bounds.");
	return data[n];
}
std::size_t Span::size() const {
	return data.size();
}
