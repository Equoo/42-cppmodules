/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:14:42 by dderny            #+#    #+#             */
/*   Updated: 2025/08/27 02:18:06 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

int main( void ) {
	Point a(Fixed(0.f), Fixed(0.f));
	Point b(Fixed(4.5f), Fixed(0.f));
	Point c(Fixed(2.25f), Fixed(7.5f));

	Point p1(Fixed(2.f), Fixed(4.f));
	Point p2(Fixed(0.f), Fixed(4.f));
	Point p3(Fixed(0.1f), Fixed(0.1f));
	Point p4(Fixed(4.4f), Fixed(0.335f));
	Point p5(Fixed(4.4f), Fixed(0.338f));

	std::cout << p1 << ", " << Point::bsp(a, b, c, p1) << std::endl;
	std::cout << p2 << ", " << Point::bsp(a, b, c, p2) << std::endl;
	std::cout << p3 << ", " << Point::bsp(a, b, c, p3) << std::endl;
	std::cout << p4 << ", " << Point::bsp(a, b, c, p4) << std::endl;
	std::cout << p5 << ", " << Point::bsp(a, b, c, p5) << std::endl;

	return (0);
}

