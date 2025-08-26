/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:12:12 by dderny            #+#    #+#             */
/*   Updated: 2025/06/18 04:22:35 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {
	firstname = "John";
	lastname = "Doe";
	phone_number = "+33601010101";
	nickname = "Marvin";
	darkest_secret = "42";
}

std::string Contact::getDarkestSecret() {
	return (darkest_secret);
}

void Contact::setDarkestSecret(std::string secret) {
	darkest_secret = secret;
}