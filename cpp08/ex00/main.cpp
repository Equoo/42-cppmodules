#include "easyfind.hpp"
#include <exception>
#include <iostream>
#include <list>
#include <deque>
#include <vector>


#define TITLE(x) std::cout << "######### " << x << " #########" << std::endl
#define PRINT(x) std::cout << x << std::endl

#define TEST(value) \
		try { \
			it = easyfind(list, value); \
			if (*it == value) \
				PRINT(__LINE__ << "- GOOD"); \
			else \
				PRINT(__LINE__ << "- WRONG: find: "#value"; get: " << *it); \
		} catch (std::exception &e) { PRINT(__LINE__ << "- WRONG: catch exception: " << e.what()); }

#define TEST_CATCH(value) \
		try { \
			it = easyfind(list, value); \
			PRINT(__LINE__ << "- WRONG: nothing catched, get: " << *it); \
		} catch (std::exception &e) { PRINT(__LINE__ << "- GOOD: catch exception: " << e.what()); }

int main( void ) {
	{
		TITLE("Test 1: Classic vector(8)");

		const int init_list[8] = { 12, 534, 213, 556, 4, 67, 23, 7 };
		std::vector<int> list(init_list, init_list + 8);

		std::vector<int>::iterator it;
		TEST(556);
		TEST(12);
		TEST(4);
		TEST(23);
		TEST_CATCH(43);
		TEST_CATCH(14);
	}

	{
		TITLE("Test 2: const vector(8)");

		const int init_list[8] = { 12, 534, 213, 556, 4, 67, 23, 7 };
		const std::vector<int> list(init_list, init_list + 8);

		std::vector<int>::const_iterator it;
		TEST(556);
		TEST(12);
		TEST(4);
		TEST(23);
		TEST_CATCH(43);
		TEST_CATCH(14);
	}

	{
		TITLE("Test 3: list");

		const int init_list[8] = { 12, 534, 213, 556, 4, 67, 23, 7 };
		std::list<int> list(init_list, init_list + 8);

		std::list<int>::iterator it;
		TEST(556);
		TEST(12);
		TEST(4);
		TEST(23);
		TEST_CATCH(43);
		TEST_CATCH(14);
	}


	{
		TITLE("Test 4: deque");

		const int init_list[8] = { 12, 534, 213, 556, 4, 67, 23, 7 };
		std::deque<int> list(init_list, init_list + 8);

	std::deque<int>::iterator it;
		TEST(556);
		TEST(12);
		TEST(4);
		TEST(23);
		TEST_CATCH(43);
		TEST_CATCH(14);
	}

	return 0;
}
