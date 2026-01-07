
#include "Point.hpp"
#include "Fixed.hpp"
#include <ostream>
#include <stdint.h>
#include <iostream>

Point::Point() : x(), y() {}
Point::Point(const float x, const float y) : x(x), y(y) {}
Point::Point(const Point &obj) : x(obj.x), y(obj.y) {}
Point::~Point() {}

Point	&Point::operator=(const Point &obj) {
	if (this == &obj)
		return (*this);
	x = obj.x;
	y = obj.y;
	return (*this);
}

bool					Point::operator<(const Point &obj) { return (x < obj.x && y < obj.y); }
bool					Point::operator>(const Point &obj) { return (x > obj.x && y > obj.y); }
bool					Point::operator<=(const Point &obj) { return (x <= obj.x && y <= obj.y); }
bool					Point::operator>=(const Point &obj) { return (x >= obj.x && y >= obj.y); }

bool					Point::operator==(const Point &obj) { return (x == obj.x && y == obj.y); }
bool					Point::operator!=(const Point &obj) { return (x != obj.x && y != obj.y); }
Point					&Point::operator+(const Point &obj) { x += obj.x; y += obj.y; return (*this); }
Point					&Point::operator-(const Point &obj) { x -= obj.x; y -= obj.y; return (*this); }
Point					&Point::operator*(const Point &obj) { x *= obj.x; y *= obj.y; return (*this); }
Point					&Point::operator/(const Point &obj) { x /= obj.x; y /= obj.y; return (*this); }

std::ostream&	operator<<(std::ostream& stream, const Point& fixed) {
	return (stream << "("  << fixed.getX() << ", " << fixed.getY() << ")");
}

Fixed	Point::getX() const { return (x); }
Fixed	Point::getY() const { return (y); }
void	Point::setX(Fixed value) { x = value; }
void	Point::setY(Fixed value) { y = value; }


bool Point::bsp( Point const a, Point const b, Point const c, Point const point) {
	
}
