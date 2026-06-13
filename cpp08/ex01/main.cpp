#include "Span.hpp"
#include <cstddef>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <vector>

#define TITLE(x) std::cout << "######### " << x << " #########" << std::endl
#define PRINT(x) std::cout << x << std::endl

#define TEST_LONGEST(value) \
		try { \
			res = span.longestSpan(); \
			if (res == value) \
				PRINT(__LINE__ << "- GOOD"); \
			else \
				PRINT(__LINE__ << "- WRONG: find: "#value"; get: " << res); \
		} catch (std::exception &e) { PRINT(__LINE__ << "- WRONG: catch exception: " << e.what()); }

#define TEST_SHORTEST(value) \
		try { \
			res = span.shortestSpan(); \
			if (res == value) \
				PRINT(__LINE__ << "- GOOD"); \
			else \
				PRINT(__LINE__ << "- WRONG: find: "#value"; get: " << res); \
		} catch (std::exception &e) { PRINT(__LINE__ << "- WRONG: catch exception: " << e.what()); }

#define TEST_THROW(value) \
		try { \
			res = span.longestSpan(); \
			PRINT(__LINE__ << "- WRONG: nothing catched, get: " << res); \
		} catch (std::exception &e) { PRINT(__LINE__ << "- GOOD: catch exception: " << e.what()); }

int main( void ) {
	{
		TITLE("Test 1: 8 numbers");

		const int init_list[8] = { 12, -534, 213, 556, 4, 67, -23, 7 };
		Span span;
		for (std::size_t i = 0; i < 8; i++)
			span.addNumber(init_list[i]);

		int res;
		TEST_LONGEST(1090);
		TEST_SHORTEST(3);
	}

	{
		TITLE("Test 2: 10000 numbers");
		Span span;
		for (std::size_t i = 0; i < 4998; i++)
			span.addNumber(std::abs(std::rand() % 10000) + 500);
		span.addNumber(100000);
		span.addNumber(5);
		for (std::size_t i = 0; i < 4998; i++)
			span.addNumber(std::abs(std::rand() % 10000) + 500);
		span.addNumber(10);
		span.addNumber(-100000);

		int res;
		TEST_LONGEST(200000);
		TEST_SHORTEST(5);
	}

	{
		TITLE("Test 3: 100K numbers");
		Span span;

		std::vector<int> numbers(100000, 24);
		span.addNumbers(numbers.begin(), numbers.end());

		int res;
		TEST_LONGEST(0);
		TEST_SHORTEST(0);
	}

	{
		TITLE("Test 3: Throws");

		Span span;
		span.addNumber(14);

		int res;
		TEST_THROW();
	}

	{
		TITLE("Test 4: Throws");

		Span span;

		int res;
		TEST_THROW();
	}
	return 0;
}

