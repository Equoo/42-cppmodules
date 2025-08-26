/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:12:12 by dderny            #+#    #+#             */
/*   Updated: 2025/06/18 04:22:35 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name) {
	name = name;
}

void Zombie::announce() {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}