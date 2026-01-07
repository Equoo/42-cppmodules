
#include "Fixed.hpp"
#include <cmath>
#include <ostream>
#include <stdint.h>
#include <iostream>

Fixed::Fixed() : value(0) {}

Fixed::Fixed(float const value) {
	setRawBits(roundf(value * (1 << fixed_point)));
}

Fixed::Fixed(int const value) {
	const int	raw = value << fixed_point;
	setRawBits(raw);
}

Fixed::Fixed(int const raw, int) {
	setRawBits(raw);
}

Fixed::Fixed(const Fixed &obj) : value(obj.value) {}

Fixed::~Fixed() {}


Fixed	&Fixed::operator=(const Fixed &obj) {
	if (this == &obj)
		return (*this);
	value = obj.getRawBits();
	return (*this);
}

bool					Fixed::operator<(const Fixed &obj) const { return (value < obj.value); }
bool					Fixed::operator>(const Fixed &obj) const { return (value > obj.value); }
bool					Fixed::operator>=(const Fixed &obj) const { return (value >= obj.value); }
bool					Fixed::operator<=(const Fixed &obj) const { return (value <= obj.value); }
bool					Fixed::operator==(const Fixed &obj) const { return (value == obj.value); }
bool					Fixed::operator!=(const Fixed &obj) const { return (value != obj.value); }

Fixed					Fixed::operator+(const Fixed &obj) const { return (Fixed(value + obj.value, 0)); }
Fixed					Fixed::operator-(const Fixed &obj) const { return (Fixed(value - obj.value, 0)); }
Fixed					Fixed::operator*(const Fixed &obj) const { return (Fixed((value * obj.value) >> fixed_point, 0)); }
Fixed					Fixed::operator/(const Fixed &obj) const { return (Fixed((value / obj.value) << fixed_point, 0)); }

Fixed					&Fixed::operator++()	{ value++; return (*this); };
Fixed					Fixed::operator++(int) 	{ Fixed	tmp(*this); value++; return (tmp); };
Fixed					&Fixed::operator--()	{ value--; return (*this); };
Fixed					Fixed::operator--(int) 	{ Fixed	tmp(*this); value--; return (tmp); };

std::ostream&	operator<<(std::ostream& stream, const Fixed& fixed) {
	return (stream << fixed.toFloat());
}

static int	round_fixed(int	const raw, int8_t const fixed_point) {
	const int	ceil = ((raw >> fixed_point) + 1) << fixed_point;
	const int	floor = raw >> fixed_point << fixed_point;
	if (raw - floor <= ceil - raw)
		return (floor);
	else
		return (ceil);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b) 				{ return (std::min(a.value, b.value) == a.value ? a : b); }
const Fixed	&Fixed::min(const Fixed &a, const Fixed &b) { return (std::min(a.value, b.value) == a.value ? a : b); }
Fixed	&Fixed::max(Fixed &a, Fixed &b) 				{ return (std::max(a.value, b.value) == a.value ? a : b); }
const Fixed	&Fixed::max(const Fixed &a, const Fixed &b) { return (std::max(a.value, b.value) == a.value ? a : b); }


float	Fixed::toFloat() const {
	return ((float)value / (1 << fixed_point));
}

int	Fixed::toInt() const {
	return (round_fixed(value, fixed_point) >> fixed_point);
}

int	Fixed::getRawBits() const {
	return (value);
}

void	Fixed::setRawBits(int const raw) {
	value = raw;
}
