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

	Point					&operator=(const Point &obj);
	bool					operator<(const Point &obj);
	bool					operator>(const Point &obj);
	bool					operator>=(const Point &obj);
	bool					operator<=(const Point &obj);
	bool					operator==(const Point &obj);
	bool					operator!=(const Point &obj);
	Point					&operator+(const Point &obj);
	Point					&operator-(const Point &obj);
	Point					&operator*(const Point &obj);
	Point					&operator/(const Point &obj);
	
	friend std::ostream&	operator<<(std::ostream& stream, const Point& point);
	
	static Point		&min(Point &a, Point &b);
	static const Point	&min(const Point &a, const Point &b);
	static Point		&max(Point &a, Point &b);
	static const Point	&max(const Point &a, const Point &b);
		
private:
	Fixed			x;
	Fixed			y;
};

#endif
