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
# include <ostream>
# include <stdint.h>

class Fixed {
public:
	Fixed();
	Fixed(int const value);
	Fixed(float const value);
	Fixed(int const raw, int);
	Fixed(const Fixed &obj);
	~Fixed();

	Fixed					&operator=(const Fixed &obj);
	Fixed					&operator+=(const Fixed &obj);
	Fixed					&operator-=(const Fixed &obj);
	Fixed					&operator*=(const Fixed &obj);
	Fixed					&operator/=(const Fixed &obj);
	bool					operator<(const Fixed &obj) const;
	bool					operator>(const Fixed &obj) const;
	bool					operator>=(const Fixed &obj) const;
	bool					operator<=(const Fixed &obj) const;
	bool					operator==(const Fixed &obj) const;
	bool					operator!=(const Fixed &obj) const;
	Fixed					operator+(const Fixed &obj) const;
	Fixed					operator-(const Fixed &obj) const;
	Fixed					operator*(const Fixed &obj) const;
	Fixed					operator/(const Fixed &obj) const;
	Fixed					&operator++();
	Fixed					operator++(int);
	Fixed					&operator--();
	Fixed					operator--(int);

	friend std::ostream&	operator<<(std::ostream& stream, const Fixed& fixed);

	float	toFloat(void) const;
	int		toInt(void) const;
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	static Fixed		&min(Fixed &a, Fixed &b);
	static const Fixed	&min(const Fixed &a, const Fixed &b);
	static Fixed		&max(Fixed &a, Fixed &b);
	static const Fixed	&max(const Fixed &a, const Fixed &b);
	static Fixed		abs(Fixed &v);

private:
	static const int8_t	fixed_point = 8;
	int			value;
};

#endif
