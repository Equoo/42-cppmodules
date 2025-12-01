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

int main() {
	Harl::setLevel("INFO");
	
	Harl::complain("DEBUG", "What is this ???");
	Harl::complain("WARNING", "Connection lost.");
	Harl::complain("INFO", "Client XX joining.");
	Harl::complain("INFO", "Connection established.");
	Harl::complain("ERROR", "XX failed to connect.");
	Harl::complain("FEUR", "Will never be printed");

	return (0);
}
