/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:14:42 by dderny            #+#    #+#             */
/*   Updated: 2025/09/19 23:52:01 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

const std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

int main(int argc, char **argv) {
	Harl			harl;
	std::string		level_str("INFO");
	int				level = -1;

	if (argc > 1)
		level_str = std::string(argv[1]);

	for (int i = 0; i < 4; i++) {
	  if (levels[i] == level_str) {
		level = i;
		break;
	  }
	}

	if (level == -1)
	{
		std::cout << "Invalid level." << std::endl;
		return (0);
	}

	harl.complain((t_harl_level)level);
	return (0);
}
