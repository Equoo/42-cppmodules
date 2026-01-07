
#include "Point.hpp"
#include "Fixed.hpp"
#include <ostream>
#include <stdint.h>
#include <iostream>

Point::Point() : x(), y() {}
Point::Point(const float x, const float y) : x(x), y(y) {}
Point::Point(const Fixed &x, const Fixed &y) : x(x), y(y) {}
Point::Point(const Point &obj) : x(obj.x), y(obj.y) {}
Point::~Point() {}

Point	&Point::operator=(const Point &obj) {
	if (this == &obj)
		return (*this);
	x = obj.x;
	y = obj.y;
	return (*this);
}

bool					Point::operator<(const Point &obj) const { return (x < obj.x && y < obj.y); }
bool					Point::operator>(const Point &obj) const { return (x > obj.x && y > obj.y); }
bool					Point::operator<=(const Point &obj) const { return (x <= obj.x && y <= obj.y); }
bool					Point::operator>=(const Point &obj) const { return (x >= obj.x && y >= obj.y); }
bool					Point::operator==(const Point &obj) const { return (x == obj.x && y == obj.y); }
bool					Point::operator!=(const Point &obj) const { return (x != obj.x && y != obj.y); }

bool					Point::operator<=(const float &v) const { return (x <= v && y <= v); }
bool					Point::operator>=(const float &v) const { return (x >= v && y >= v); }
bool					Point::operator<(const float &v) const { return (x < v && y < v); }
bool					Point::operator>(const float &v) const { return (x > v && y > v); }
bool					Point::operator==(const float &v) const { return (x == v && y == v); }
bool					Point::operator!=(const float &v) const { return (x != v && y != v); }

Point					Point::operator+(const Point &obj) const { return (Point(x + obj.x, y + obj.y)); }
Point					Point::operator-(const Point &obj) const { return (Point(x - obj.x, y - obj.y)); }
Point					Point::operator*(const Point &obj) const { return (Point(x * obj.x, y * obj.y)); }
Point					Point::operator/(const Point &obj) const { return (Point(x / obj.x, y / obj.y)); }

std::ostream&	operator<<(std::ostream& stream, const Point& fixed) {
	return (stream << "("  << fixed.getX() << ", " << fixed.getY() << ")");
}

Fixed	Point::getX() const { return (x); }
Fixed	Point::getY() const { return (y); }
void	Point::setX(Fixed value) { x = value; }
void	Point::setY(Fixed value) { y = value; }

Point	Point::cross(const Point &a, const Point &b) { return (Point(a.x * b.y - a.y * b.x, a.x * b.y - a.y * b.x)); }

static int	get_orient(const Point &a, const Point &b, const Point &c) {
	Point ab = b - a;
	Point ac = c - a;

	if (Point::cross(ab, ac) > 0.f)
		return (1);
	else
		return (-1);
}

// Approach of the orientation
bool Point::bsp( Point const a, Point const b, Point const c, Point const point) {
	Fixed	orients = get_orient(a, b, point) + get_orient(b, c, point) + get_orient(c, a, point);

	if (Fixed::abs(orients) == Fixed(3.f))
		return (true);
	else
		return (false);
}
