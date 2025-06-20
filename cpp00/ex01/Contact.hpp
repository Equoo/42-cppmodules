/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:53:43 by dderny            #+#    #+#             */
/*   Updated: 2025/06/18 04:22:47 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <string>

class Contact {
	public:
		Contact();
		std::string getDarkestSecret();
		void setDarkestSecret(std::string secret);

	public:
		std::string firstname;
		std::string lastname;
		std::string phone_number;
		std::string nickname;
		
	private:
		std::string darkest_secret;
};

#endif