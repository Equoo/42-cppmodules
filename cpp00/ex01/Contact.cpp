/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:12:12 by dderny            #+#    #+#             */
/*   Updated: 2025/10/28 22:46:04 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

using std::string;

Contact::Contact()
	: firstname(),
	lastname(),
	phone_number(),
	nickname(), 
	darkest_secret() {}

Contact::Contact(string firstname, string lastname, string phonenumber,
	string nickname, string darkest_secret)
	: firstname(firstname),
	lastname(lastname),
	phone_number(phonenumber),
	nickname(nickname), 
	darkest_secret(darkest_secret) {}

Contact::~Contact() {}

string Contact::getDarkestSecret() const {
	return (darkest_secret);
}

string Contact::getFirstName() const {
	return (firstname);
}

string Contact::getLastName() const {
	return (lastname);
}

string Contact::getNickname() const {
	return (nickname);
}

string Contact::getPhoneNumber() const {
	return (phone_number);
}
