/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:14:42 by dderny            #+#    #+#             */
/*   Updated: 2025/08/27 03:56:27 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <climits>
#include <cstdlib>
#include <cstring>
#include <exception>
#include <iostream>
#include <ostream>
#include <string>
#include <cerrno>

void	test_hordes( int N, std::string name ) {
	std::cout << "Creating a horde of " << N << " zombies named " << name << ":" << std::endl;
	
	Zombie	*zombies = zombieHorde( N, name );

	if (!zombies) {
		std::cout << "Allocation failed" << std::endl;
		return;
	}

	for (int i = 0; i < N; i++) {
		std::cout << "\tzombie " << i << ": ";
		zombies[i].announce();
	}

	delete [] zombies;
}

int	main( int argc, char **argv ) {
	try {
		if (argc != 3) {
			std::cout << "Usage: <horde size> <zombies name>." << std::endl;
			return (EXIT_SUCCESS);
		}

		char		*endptr;
		long		N = std::strtol(argv[1], &endptr, 0);
		std::string	name = std::string(argv[2]);
		
		if (endptr && *endptr)
			throw std::runtime_error(std::string("Conversion failed: isn't a valid number."));
		if (errno != 0)
			throw std::runtime_error(std::string("Conversion failed: ") + std::strerror(errno));
		if (N < 0)
			throw std::runtime_error(std::string("Horde size must be positive."));
		if (N > INT_MAX)
			throw std::runtime_error(std::string("Horde size must be inferior to INT_MAX."));

		test_hordes(N, name);
	} catch (const std::exception &err) {
		std::cerr << "An error occured:\n\t" << err.what() << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}