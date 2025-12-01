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

static void	test_hordes( int n, std::string name ) {
	std::cout << "Creating a horde of "
		<< n << " zombies named "
		<< name << ":" << std::endl;
	
	Zombie	*zombies = zombieHorde( n, name );

	for (int i = 0; i < n; i++) {
		std::cout << "\tzombie " << i << ": ";
		zombies[i].announce();
	}

	delete [] zombies;
}

static void	process_args(char **args, long &n, std::string &name) {
	char		*endptr;

	n = std::strtol(args[1], &endptr, 0);
	name = std::string(args[2]);	
	if (endptr && *endptr)
		throw std::runtime_error(std::string("Conversion failed: isn't a valid number."));
	if (errno != 0)
		throw std::runtime_error(std::string("Conversion failed: ") + std::strerror(errno));
	if (n < 0)
		throw std::runtime_error(std::string("Horde size must be positive."));
	if (n > INT_MAX)
		throw std::runtime_error(std::string("Horde size must be inferior to INT_MAX."));	
}

int	main( int argc, char **argv ) {
	long		n;
	std::string	name;

	try {
		if (argc != 3) {
			std::cout << "Usage: <horde size> <zombies name>." << std::endl;
			return (EXIT_SUCCESS);
		}
		
		process_args(argv, n, name);		
		test_hordes(n, name);
	} catch (const std::exception &err) {
		std::cout << "An error occured:\n\t" << err.what() << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
