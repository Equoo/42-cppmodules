#pragma once

#include <cstddef>

template<typename T, typename U>
void iter(T *array, const size_t len, U fn) {
	for (size_t i = 0; i < len; i++) {
		fn(array[i]);
	}
}

template<typename T, typename U>
void iter(const T *array, const size_t len, U fn) {
	for (size_t i = 0; i < len; i++) {
		fn(array[i]);
	}
}
