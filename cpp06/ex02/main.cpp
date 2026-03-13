
#include <stdint.h>

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include "log.hpp"

using std::string;

Base *generate(void) {
	switch (rand() % 3) {
		case 0:
			return new A;
		case 1:
			return new B;
		default:
			return new C;
	}
}

void identify(Base *p) {
	if (dynamic_cast<A*>(p))
		PRINTLN("Identified as A.");
	else if (dynamic_cast<B*>(p))
		PRINTLN("Identified as B.");
	else if (dynamic_cast<C*>(p))
		PRINTLN("Identified as C.");
}

void identify(Base &p) {
	try {
		(void)dynamic_cast<A&>(p);
		PRINTLN("Identified as A.");
		return;
	} catch (...) {}
	try {
		(void)dynamic_cast<B&>(p);
		PRINTLN("Identified as B.");
		return;
	} catch (...) {}
	try {
		(void)dynamic_cast<C&>(p);
		PRINTLN("Identified as C.");
		return;
	} catch (...) {}
}

void test_rand_ptr() {
	Base *v = generate();
	identify(v);
	delete v;
}

void test_rand_ref() {
	Base *v = generate();
	identify(*v);
	delete v;
}

int main() {
	srand(time(NULL));

	PRINTLN("Test rand:");
	for (int i = 0; i < 10; i++)
		test_rand_ptr();
	for (int i = 0; i < 10; i++)
		test_rand_ref();

	PRINTLN();
	PRINTLN("Test ordered:");

	A a;
	B b;
	C c;

	identify(&a);
	identify(&b);
	identify(&c);
	identify(a);
	identify(b);
	identify(c);

	return (0);
}
