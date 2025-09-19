/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:14:42 by dderny            #+#    #+#             */
/*   Updated: 2025/09/19 23:52:01 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <iostream>
#include <fstream>
#include <cstdlib>

int main(int argc, char **argv) {
	if (argc != 4) {
		std::cout << "Not enough arguments.\n" << "Usage: ./fsnr <file path> <string to replace> <new string>" << std::endl;
		return (0);
	}
	
	char			*path = argv[1];
	std::string		s1(argv[2]); // if newline !=
	std::string		s2(argv[3]);
	
	size_t			s1_size = s1.size();
	size_t			s2_size = s2.size();
	size_t			diff_size = s2_size - s1_size;
	
	try {
		std::ifstream	input(path);
		std::ofstream	output(std::string(path).append(".replace").c_str());
		std::string		line;
		while (getline(input, line)) {
			size_t			next_pos = 0;
			size_t			line_size = line.size();
			while (next_pos < line_size)
			{
				size_t	start_pos = 0;
				start_pos = line.find(s1, next_pos);
				if (start_pos == (size_t)-1)
					break;
				next_pos = start_pos + s2_size;
				line_size += diff_size;
				line.erase(start_pos, s1_size);
				line.insert(start_pos, s2);
			}
			output << line;
			if (!input.eof())
				output << std::endl;
		}
		
		input.close();
		output.close();	
	} catch (const std::exception &err) {
		std::cerr << "An error occured:\n\t" << err.what() << std::endl;
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}