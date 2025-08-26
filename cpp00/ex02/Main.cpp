/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:14:42 by dderny            #+#    #+#             */
/*   Updated: 2025/06/20 03:05:17 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <cassert>
#include <cerrno>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <ostream>
#include <string>
#include <stdlib.h>

static bool parse_int(const std::string &str, int &out_value) {
    char *endptr = NULL;
    errno = 0;
    long value = strtol(str.c_str(), &endptr, 10);

    if (endptr == str.c_str()) {
        return false;
    }
    while (*endptr != '\0') {
        if (!isspace(*endptr)) // Allow trailing spaces
            return false;
        ++endptr;
    }
    if (errno == ERANGE || value < INT_MIN || value > INT_MAX) {
        return false;
    }
    out_value = static_cast<int>(value);
    return true;
}

static std::string	ask(const char *prompt = "") {
	std::string response;
	
	std::cout << prompt << "> ";
	if (!getline(std::cin, response))
		errno = EOF;
	return (response);
}

static void	add_cmd(PhoneBook *phonebook) {
	Contact	new_contact;

	std::cout << "Fill these informations about the contact:" << std::endl;
	
	new_contact.firstname = ask("Firstname");
	new_contact.lastname = ask("Lastname");
	new_contact.nickname = ask("Nickname");
	new_contact.phone_number = ask("Phone Number");
	new_contact.setDarkestSecret(ask("Darkest Secret"));

	phonebook->add(new_contact);
	
	std::cout << new_contact.firstname << " "
			<< new_contact.lastname << " was correctly added." << std::endl;
}

static std::string	truncate_str(std::string str, const std::size_t size) {
	if (str.length() > size) {
		str.resize(size - 1);
		str.append(".");
	}
	return (str);
}

static void	search_cmd(PhoneBook *phonebook) {
	const int size = phonebook->getSize();
	const Contact *list = phonebook->getAll();;
	Contact	contact;

	if (size == 0) {
		std::cout << "No contacts found." << std::endl;
		return ;
	}
	
	std::cout << std::endl << "---------------------------------------------" << std::endl;
	std::cout << "|"
		<< std::setw(10) << "Index" << "|"
		<< std::setw(10) << "Firstname" << "|"
		<< std::setw(10) << "Lastname" << "|"
		<< std::setw(10) << "Nickname" << "|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	for (int i = 0; i < size; i++) {
		contact = list[i];
		std::cout << "|"
			<< std::setw(10) << i << "|"
			<< std::setw(10) << truncate_str(contact.firstname, 10) << "|"
			<< std::setw(10) << truncate_str(contact.lastname, 10) << "|"
			<< std::setw(10) << truncate_str(contact.nickname, 10) << "|" << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl << std::endl;

	int searched = 0;
	if (!parse_int(ask("Enter the searched contact id"), searched)) {
		std::cout << "Invalid input: only integer of 0 to phone book size is allowed." << std::endl;
		return;
	}
	if (searched > size || searched < 0) {
 		std::cout << "Invalid input: index is out of range." << std::endl;
		return;
	}

	contact = list[searched];
	std::cout << std::endl
		<< "Firstname	:  " << contact.firstname << std::endl
		<< "Lastname	:  " << contact.lastname << std::endl
		<< "Nickname	:  " << contact.nickname << std::endl
		<< "Phone Number	:  " << contact.phone_number << std::endl
		<< "Darkest Secret	:  " << contact.getDarkestSecret() << std::endl;
}

int	main () {
	PhoneBook	phoneBook;
	bool		running = true;
	std::string	cmd = "";
	
	do {
		errno = 0;
		cmd = ask("nokia3310");
		
		if (cmd == "ADD")
			add_cmd(&phoneBook);
		else if (cmd == "SEARCH")
			search_cmd(&phoneBook);
		else if (errno || cmd == "EXIT")
			running = false;
		else
			std::cout << "Unknown command." << std::endl;
	} while (running);

	return (0);
}