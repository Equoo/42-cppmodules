
#include "Array.hpp"
#include "log.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

#define MAX_VAL 750

void test_1() {
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cout << "didn't save the same value!!" << std::endl;
            return;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
}

void test_2() {
	try {
		Array<std::string> test;
		PRINTLN("Size: ", test.size());

		test[0] = "feur";
	} catch (const std::exception& e) {
        std::cout << e.what() << '\n';
	}
}

int main(int, char**)
{
	test_1();
	test_2();
    return 0;
}
