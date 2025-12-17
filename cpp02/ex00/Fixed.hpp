/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:53:43 by dderny            #+#    #+#             */
/*   Updated: 2025/08/27 02:53:09 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <stdint.h>

class Fixed {
public:
	Fixed();
	Fixed(const Fixed &obj);
	~Fixed();
	Fixed	&operator=(const Fixed &obj);
	int	getRawBits(void) const;
	void	setRawBits(int const raw);
		
private:
	static const int8_t	fixed_point = 8;
	int			value;
};

#endif
