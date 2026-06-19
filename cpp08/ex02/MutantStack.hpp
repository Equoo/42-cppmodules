#pragma once

#include <deque>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
   public:
	MutantStack() : std::stack<T>() {};
	MutantStack(MutantStack &other) : std::stack<T>(other) {}
	MutantStack &operator=(MutantStack &other) {
		std::stack<T>::operator=(other);
		return (*this);
	}
	virtual ~MutantStack() {}

	typedef typename std::deque<T>::iterator iterator;

	iterator begin() {
		return this->c.begin();
	}

	iterator end() {
		return this->c.end();
	}
};

