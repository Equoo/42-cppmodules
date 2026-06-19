#include <iostream>
#include <vector>
#include "MutantStack.hpp"

void test_mutated_stack() {
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
}

void test_vector() {
	std::vector<int> mvec;
	mvec.push_back(5);
	mvec.push_back(17);
	std::cout << mvec.back() << std::endl;
	mvec.pop_back();
	std::cout << mvec.size() << std::endl;
	mvec.push_back(3);
	mvec.push_back(5);
	mvec.push_back(737);
	//[...]
	mvec.push_back(0);
	std::vector<int>::iterator it = mvec.begin();
	std::vector<int>::iterator ite = mvec.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
}

int main()
{
	std::cout << "Control test using vector:" << std::endl;
	test_vector();
	std::cout << "Test using MutatedStack:" << std::endl;
	test_mutated_stack();
	return 0;
}
