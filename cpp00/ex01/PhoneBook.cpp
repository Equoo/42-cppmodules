/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:53:49 by dderny            #+#    #+#             */
/*   Updated: 2025/10/28 23:38:54 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <cstdlib>
#include <limits>
#include <ostream>
#include <stdexcept>
#include <string>
#include <iomanip>
#include <iostream>
#include <sys/types.h>

using std::cin;
using std::cout;

PhoneBook::PhoneBook() : contacts(), size(0), last_added(0) {}

PhoneBook::~PhoneBook() {}

static bool	has_extra_input() {
    return !cin.eof() && cin.peek() != '\n';
}

static void	ignore_line() {
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

static std::string	prompt(std::string prompt, bool is_line) {
	std::string	response;
	
	cout << prompt << " ➜ ";
	if (is_line)
		std::getline(std::cin >> std::ws, response);
	else
		cin >> response;	
	if (!cin) {
		if (cin.eof()) {
			std::exit(0);
		}

		cin.clear();
		ignore_line();
		throw std::invalid_argument("Invalid input.");
	}	

	return (response);
}

static int prompt_int(std::string prompt) {
	int	response;
	
	cout << prompt << " ➜ ";	
	cin >> response;
	if (!cin) {
		if (cin.eof()) {
			std::exit(0);
		}

		cin.clear();
		ignore_line();
		throw std::invalid_argument("Invalid input: must be a int.");
	}
	if (has_extra_input()) {
		ignore_line();
		throw std::invalid_argument("Invalid input: must be a int.");
	}

	return (response);
}

void	PhoneBook::start() {
	while (1) {
		try {
			if (this->prompt_command())
				return;
		} catch( const std::exception & e ) {
			std::cout << e.what() << std::endl;
		} catch( ... ) {
			std::cout << "Another unknown error" << std::endl;
	    }
	}
}

bool	PhoneBook::prompt_command() {
	std::string	cmd = prompt("Use one of these three commands: ADD, SEARCH, EXIT.\nnokia3310", false);

	if (cmd == "ADD")
		this->add_cmd();
	else if (cmd == "SEARCH")
		this->search_cmd();
	else if (cmd == "EXIT")
		return (true);
	else
		throw std::invalid_argument("Unknown command.");

	return (false);
}


void	PhoneBook::add_cmd() {
	cout << "Fill these informations about the contact:" << std::endl;
	Contact	new_contact(
		prompt("Firstname", false),
		prompt("Lastname", false),
		prompt("Nickname", false),
		prompt("Phone number", false),
		prompt("Darkest secret", true)
	);

	this->contact_add(new_contact);	
	cout << new_contact.getFirstName() << " "
			<< new_contact.getLastName() << " was correctly added." << std::endl;
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

	cout << std::endl << "---------------------------------------------" << std::endl;
	cout << "|"
		<< std::setw(10) << "Index" << "|"
		<< std::setw(10) << "Firstname" << "|"
		<< std::setw(10) << "Lastname" << "|"
		<< std::setw(10) << "Nickname" << "|" << std::endl;
	cout << "|----------|----------|----------|----------|" << std::endl;
	for (int i = 0; i < size; i++) {
		contact = list[i];
		cout << "|"
			<< std::setw(10) << i << "|"
			<< std::setw(10) << truncate_str(contact.getFirstName(), 10) << "|"
			<< std::setw(10) << truncate_str(contact.getLastName(), 10) << "|"
			<< std::setw(10) << truncate_str(contact.getNickname(), 10) << "|" << std::endl;
	}
	cout << "---------------------------------------------" << std::endl << std::endl;
}

void	PhoneBook::search_cmd() {
	const int size = this->size;
	const Contact *list = this->contacts;
	Contact	contact;
	
	show_table(list, size);
	if (size == 0)
		return;

	int searched = prompt_int("Enter the searched contact id");
	if (searched >= size || searched < 0)
		throw std::invalid_argument("Invalid input: Must be superior to 0 and inferior to N contacts.");
	
	contact = list[searched];
	cout << std::endl
		<< "Firstname	:  " << contact.getFirstName() << std::endl
		<< "Lastname	:  " << contact.getLastName() << std::endl
		<< "Nickname	:  " << contact.getNickname() << std::endl
		<< "Phone Number	:  " << contact.getPhoneNumber() << std::endl
		<< "Darkest Secret	:  " << contact.getDarkestSecret() << std::endl;
}


void	PhoneBook::contact_add(Contact contact) {
	int new_index = this->last_added;

	if (new_index > 7)
		new_index = 0;

	this->contacts[new_index] = contact;
	if (size < 8)
		size++;

	this->last_added = new_index + 1;
}
