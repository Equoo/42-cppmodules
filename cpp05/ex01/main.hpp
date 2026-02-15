
#pragma once

#include "log.hpp"
#include <typeinfo>
#include <iostream>


template <typename T>
void test_one_copy(const T &a)
{
	PRINTLN("# A = ", a);
	
	T	b = T(a);
	PRINTLN("# B = ", b);
}

template <typename T>
void test_one_assignement(const T &a)
{
	T	b = T();

	PRINTLN("# B = ", b);
	PRINTLN("# Assignement of ", a);
	b = a;
	PRINTLN("# B = ", b);
}

