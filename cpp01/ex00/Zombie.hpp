/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:53:43 by dderny            #+#    #+#             */
/*   Updated: 2025/08/05 17:01:22 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <string>

class Zombie {
	public:
		Zombie(std::string name);
		std::string name;

	public:
		void announce( void );
};

Zombie	*newZombie( std::string name );
void	randomChump( std::string name );

#endif