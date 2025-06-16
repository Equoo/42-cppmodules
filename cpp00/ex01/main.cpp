/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:14:42 by dderny            #+#    #+#             */
/*   Updated: 2025/06/16 18:17:34 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

static void	ask(std::string *response, const char *prompt = "") {
	std::cout << prompt << "> ";
	std::cin >> *response;
}

static void	add_cmd(PhoneBook *phonebook) {
	Contact	new_contact;

	std::cout << "Fill these informations about the contact:" << std::endl;
	
	ask(&new_contact.firstname, "Firstname");
	ask(&new_contact.lastname, "Lastname");
	ask(&new_contact.nickname, "Nickname");
	ask(&new_contact.phone_number, "Phone Number");
	ask(&new_contact.darkest_secret, "Darkest Secret");

	phonebook->add(new_contact);
	
	std::cout << new_contact.firstname << " "
			<< new_contact.lastname << " was correctly added." << std::endl;
}

static void	search_cmd(PhoneBook *phonebook) {
	(void)phonebook;
}

int	main () {
	PhoneBook	phoneBook;
	bool		running = true;
	std::string	cmd = "";
	
	do {
		ask(&cmd, "nokia3310");
		
		if (cmd == "ADD")
			add_cmd(&phoneBook);
		else if (cmd == "SEARCH")
			search_cmd(&phoneBook);
		else if (cmd == "EXIT")
			running = false;
		else
			std::cout << "Unknown command." << std::endl;
	} while (running);

	return (0);
}