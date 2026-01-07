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

#ifndef POINT_HPP
# define POINT_HPP
# include <ostream>
# include <stdint.h>
# include "Fixed.hpp"

class Point {
public:
	Point();
	Point(const float x, const float y);
	Point(const Point &point);
	~Point();

	Point	&operator=(const Point &obj);
	bool	operator<(const Point &obj);
	bool	operator>(const Point &obj);
	bool	operator>=(const Point &obj);
	bool	operator<=(const Point &obj);
	bool	operator==(const Point &obj);
	bool	operator!=(const Point &obj);
	Point	&operator+(const Point &obj);
	Point	&operator-(const Point &obj);
	Point	&operator*(const Point &obj);
	Point	&operator/(const Point &obj);

	Fixed	getX() const;
	Fixed	getY() const;	
	void	setX(Fixed value);
	void	setY(Fixed value);

	static bool bsp( Point const a, Point const b, Point const c, Point const point);
	
private:
	Fixed	x;
	Fixed	y;
};

std::ostream&	operator<<(std::ostream& stream, const Point& point);

#endif
