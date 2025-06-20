/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:53:49 by dderny            #+#    #+#             */
/*   Updated: 2025/06/18 05:02:19 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook() {
	contacts = new Contact[8];
	size = 0;
	last_added = 7;
}

PhoneBook::~PhoneBook() {
	delete[] contacts;
	last_added = 0;
}

void	PhoneBook::add(Contact contact) {
	int new_index = last_added + 1;

	if (new_index > 7)
		new_index = 0;

	contacts[new_index] = contact;
	if (size < 8)
		size++;

	last_added = new_index;
}

Contact	*PhoneBook::getAll() {
	return (contacts);
}

int PhoneBook::getSize() {
	return (size);
}