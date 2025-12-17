
#include "Fixed.hpp"
#include <cmath>
#include <ostream>
#include <stdint.h>
#include <iostream>

Fixed::Fixed() : value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(float const value) {
	std::cout << "Float constructor called" << std::endl;
	setRawBits(roundf(value * (1 << fixed_point)));
}

Fixed::Fixed(int const value) {
	std::cout << "Int constructor called" << std::endl;
	const int	raw = value << fixed_point;
	setRawBits(raw);
}

Fixed::Fixed(const Fixed &obj) : value(obj.value) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}


Fixed	&Fixed::operator=(const Fixed &obj) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &obj)
		return (*this);
	value = obj.getRawBits();
	return (*this);
}
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
