/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:53:43 by dderny            #+#    #+#             */
/*   Updated: 2025/06/18 04:13:58 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"

class PhoneBook {
public:
	PhoneBook();
	~PhoneBook();
	void	start();	

private:
	bool	prompt_command();

	void	add_cmd();
	void	search_cmd();

	void	contact_add(Contact contact);
	void	contact_(Contact contact);

private:
	Contact	contacts[8];
	size_t	size;
	size_t	last_added;
};

#endif
