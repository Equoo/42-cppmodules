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

Contact::Contact()
	: firstname(),
	lastname(),
	phone_number(),
	nickname(), 
	darkest_secret() {}

Contact::~Contact() {}

std::string Contact::getDarkestSecret() const {
	return (darkest_secret);
}

void Contact::setDarkestSecret(std::string secret) {
	darkest_secret = secret;
}
