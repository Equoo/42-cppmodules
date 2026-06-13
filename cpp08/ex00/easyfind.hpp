
#pragma once
#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T &list, int value) {
	const typename T::iterator it = std::find(list.begin(), list.end(), value);

	if (it != list.end())
		return (it);
	else
		throw std::runtime_error("No such value in container");
}

template <typename T>
typename T::const_iterator easyfind(const T &list, int value) {
	const typename T::const_iterator it = std::find(list.begin(), list.end(), value);

	if (it != list.end())
		return (it);
	else
		throw std::runtime_error("No such value in container");
}
