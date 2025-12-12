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

#include <stdint.h>
#include <cstdlib>
#include <printf.h>
#include <exception>
#include <iostream>
#include <ostream>

#include <cmath>
#include <cstring>
#include <ieee754.h>

#define MANTISSA_MASK 0xFFFFFF
#define EXPONENT_MASK 0x7F000000
#define EXPONENT_SHIFT 24
#define SIGN_SHIFT 31


#define LOG2_10 3.321928095
#define EPSILON 0.0000001

#define flt_zero(x) (fabs(x) < EPSILON)

int max_digs_rt = 3;  /* maximum # of 0's right of decimal before using
                         scientific notation */
int max_digs_lf = 5;  /* max # of digits left of decimal */

void print_real(double r, int width, int dec)
{
    int mag;
    double fpart, temp;
    char format[8];
    char num_format[3] = {'l',0,0};
    union ieee754_double *dl;
 
    dl = (union ieee754_double*)&r;
    mag = (dl->ieee.exponent - IEEE754_DOUBLE_BIAS) / LOG2_10;
    if (r == 0)
        mag = 0;
    if ((mag > max_digs_lf-1) || (mag < -max_digs_rt)) {
        num_format[1] = 'e';
        temp = r/pow(10, mag);      /* see if number will have a decimal */
        fpart = temp - floor(temp); /* when written in scientific notation */
    }
    else {
        num_format[1] = 'f';
        fpart = r - floor(r);
    }
    if (flt_zero(fpart))
        dec = 0;
    if (width == 0) {
        snprintf(format, 8, "%%.%d%s", dec, num_format);
    }
    else {
        snprintf(format, 8, "%%%d.%d%s", width, dec, num_format);
    }
    printf(format, r);
}

int	main() {
	try {	
		// float v_f = -1.f;
		// ieee754_float	v;
		// uint32_t			v_i;
		//
		// memcpy(&v, &v_f, sizeof(float));
		// memcpy(&v_i, &v_f, sizeof(float));
		//
		// uint32_t		mantissa = v_i & MANTISSA_MASK;
		// int32_t		exponent = (v_i & EXPONENT_MASK >> EXPONENT_SHIFT) - 127;
		// uint32_t		sign = v_i >> SIGN_SHIFT;
		//
		// std::cout << "Mantissa: " << mantissa << "; Exponent: " << exponent << "; Sign: " << sign << std::endl;
		print_real(-1.f, 4, 4);
	} catch (std::exception e) {
		std::cout << "Error: " << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
