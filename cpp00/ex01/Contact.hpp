/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:53:43 by dderny            #+#    #+#             */
/*   Updated: 2025/10/28 15:34:44 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <string>

class Contact {
	public:
		Contact();
		~Contact();
		std::string getDarkestSecret() const;
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
