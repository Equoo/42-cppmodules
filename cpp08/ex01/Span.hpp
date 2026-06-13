#pragma once

#include <cstddef>
#include <vector>

class Span {
   public:
	Span();
	Span(Span &other);
	Span &operator=(Span &other);
	~Span();

	void addNumber(int nb);
	template<typename T>
	void addNumbers(T begin, T end) {
		data.insert(data.end(), begin, end);
	}

	int longestSpan() const;
	int shortestSpan() const;
	const int &operator[](unsigned int n) const;
	std::size_t size() const;

   private:
	std::vector<int> data;
};

