/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:14:42 by dderny            #+#    #+#             */
/*   Updated: 2025/08/27 02:18:06 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <cstdlib>
#include <exception>
#include <iostream>
#include <ostream>

void	testRandomChump(std::string name)
{
	std::cout << "Random chump named: `" << name << "`" << std::endl;
	randomChump(name);		
}

void	testNewZombie(std::string name)
{
	std::cout << "New zombie named: `" << name << "`" << std::endl;
	Zombie *zombie = newZombie(name);
	
	zombie->announce();
	delete zombie;
}

int	main() {
	try {
		testRandomChump("jacob");
		testRandomChump("Smith");
		testRandomChump("Steve J. ~Watson");

		testNewZombie("Jacob");
		testNewZombie("Smith");
		testNewZombie("Steve J. ~Watson");
	} catch (std::exception e) {
		std::cout << "Error: " << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
