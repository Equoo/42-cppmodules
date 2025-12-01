/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:14:42 by dderny            #+#    #+#             */
/*   Updated: 2025/08/27 05:01:30 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdio>
#include <string>
#include <sys/types.h>

int	main() {
	std::string		str = std::string("HI THIS IS BRAIN");
	std::string		*stringPTR = &str;
	std::string		&stringREF = str;

	printf("adress of str:\t\t%p\n", &str);
	printf("adress of stringPTR:\t%p\n", &stringPTR);
	printf("adress of stringREF:\t%p\n", &stringREF);
	printf("value of str:\t\t%s\n", str.c_str());
	printf("value of stringPTR:\t%lx\n", (ulong)stringPTR);
	printf("value of stringREF:\t%s\n", stringREF.c_str());
}
