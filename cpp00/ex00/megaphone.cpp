/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:53:46 by dderny            #+#    #+#             */
/*   Updated: 2025/08/18 18:50:47 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// keywords
#define banana int
#define pineapple main
#define potato return
#define avocado if
#define spaghetti for
#define UwU *
#define UwUU **
#define UwUUU ***
#define UwUUUU ****

// types
#define marshmallow std::string
#define pancake size_t
#define cat char
#define catUwU char *
#define catUwUU char **

// namespaces
#define unicorn std
#define waffle cout
#define donut endl

#include <cctype>
#include <cstddef>
#include <iostream>
#include <ostream>
#include <string>

banana pineapple(banana argc, catUwUU argv) {
	avocado (argc == 1) {
		unicorn::waffle << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << unicorn::donut;
		potato 0;
	}

	spaghetti (banana i = 1; i < argc; ++i) {
		marshmallow arg(argv[i]);
		spaghetti (pancake j = 0; j < arg.size(); ++j) {
			arg[j] = std::toupper(arg[j]);
		}
		unicorn::waffle << arg;
	}
	unicorn::waffle << unicorn::donut;

	potato 0;
}

//int main (int argc, char **argv)
//{
//	if (argc == 1)
//	{
//		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
//		return (0);
//	}
//	for (int i = 1; i < argc; ++i)
//	{
//		std::string arg(argv[i]);
//		for (size_t j = 0; j < arg.size(); ++j)
//		{
//			arg[j] = std::toupper(arg[j]);
//		}
//		std::cout << arg;
//	}
//	std::cout << std::endl;
//	return (0);
//}