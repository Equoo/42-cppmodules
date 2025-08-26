/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:14:42 by dderny            #+#    #+#             */
/*   Updated: 2025/07/08 09:47:19 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <cassert>
#include <cerrno>
#include <cstddef>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <limits>
#include <ostream>
#include <string>
#include <stdlib.h>

static int	check_input() {
	if (std::cin.eof()) {
		errno = EOF; // Set errno to EOF if end of file is reached
	}
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore();
	}
	return (0);
}

static std::string	ask(const char *prompt = "") {
	char 		c_response[2048];
	
	std::cout << prompt << "> ";	
	std::cin.getline(c_response, 2048);
	
	check_input();
	return (std::string(c_response));
}

static int	ask_int(const char *prompt = "") {
	int	value;
	
	std::cout << prompt << "> ";	
	std::cin >> value;

	if (std::cin.flags() & std::ios::failbit) {
		std::cin.clear(); // Clear the fail state
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the invalid input
		throw std::invalid_argument("Invalid input for integer.");
	}
	
	check_input();
	return (value);
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

static void show_table(const Contact *list, const int size) {
	Contact	contact;

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
}

static void	search_cmd(PhoneBook *phonebook) {
	const int size = phonebook->getSize();
	const Contact *list = phonebook->getAll();;
	Contact	contact;

	if (size == 0) {
		std::cout << "No contacts found." << std::endl;
		return ;
	}
	
	show_table(list, size);

	int searched = ask_int("Enter the searched contact id");
	if (!(searched >= 0 && searched < size))
		throw std::invalid_argument("Invalid input: Must be superior to 0 and inferior to N contacts.");
	contact = list[searched];
	std::cout << std::endl
		<< "Firstname	:  " << contact.firstname << std::endl
		<< "Lastname	:  " << contact.lastname << std::endl
		<< "Nickname	:  " << contact.nickname << std::endl
		<< "Phone Number	:  " << contact.phone_number << std::endl
		<< "Darkest Secret	:  " << contact.getDarkestSecret() << std::endl;
}

int	main() {
	PhoneBook	phoneBook;
	bool		running = true;
	std::string	cmd = "";
	
	do {
		errno = 0;
		cmd = ask("nokia3310");
		
		try {
			if (cmd == "ADD")
				add_cmd(&phoneBook);
			else if (cmd == "SEARCH")
				search_cmd(&phoneBook);
			else if (cmd == "EXIT")
				running = false;
			else if (cmd == "")
				continue;
			else
				std::cout << "Unknown command." << std::endl;
		} catch( const std::exception & e ) {
			std::cerr << e.what() << std::endl;
		} catch( ... ) {
			std::cerr << "Another unknown error" << std::endl;
	    }
	} while (running && !errno);
	return (0);
}