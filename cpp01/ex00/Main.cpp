/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:14:42 by dderny            #+#    #+#             */
/*   Updated: 2025/08/05 17:11:20 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
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
}

int	main() {
	testRandomChump("jacob");
	testRandomChump("Smith");
	testRandomChump("Steve J. ~Watson");

	testNewZombie("Jacob");
	testNewZombie("Smith");
	testNewZombie("Steve J. ~Watson");
}