
#pragma once

#include "log.hpp"
#include <typeinfo>
#include <iostream>


template <typename T>
void test_one_copy(const T *obj)
{
	PRINTLN("# Copy of ", typeid(obj).name());
	T _ = T(*obj);
	delete obj;
}

template <typename T>
void test_one_assignement(const T *obj)
{
	PRINTLN("# Assignement of ", typeid(obj).name());
	T	a = T();
	a = *obj;
	delete obj;
}

