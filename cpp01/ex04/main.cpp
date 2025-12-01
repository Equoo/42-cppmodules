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

using std::string;

static void	replace_line_occurencies(string &line, string &s1, string &s2) {
	const size_t	s1_size = s1.size();
	const size_t	s2_size = s2.size();
	const size_t	diff_size = s2_size - s1_size;
	size_t			line_size = line.size();
	size_t			next_pos = 0;
	
	while (next_pos < line_size)
	{
		size_t	start_pos = line.find(s1, next_pos);
		if (start_pos == (size_t)-1)
			break;
		next_pos = start_pos + s2_size;
		line_size += diff_size;
		line.erase(start_pos, s1_size);
		line.insert(start_pos, s2);
	}
}

int main(int argc, char **argv) {
	if (argc != 4) {
		std::cout << "Not enough arguments.\n" << "Usage: ./fsnr <file path> <string to replace> <new string>" << std::endl;
		return (0);
	}
		
	try {
		char			*path = argv[1];
		string			s1(argv[2]);
		string			s2(argv[3]);

		std::ifstream	input(path);
		std::ofstream	output(string(path).append(".replace").c_str());
		string			line;

		while (getline(input, line)) {
			replace_line_occurencies(line, s1, s2);
			output << line;
			if (!input.eof())
				output << std::endl;
		}
		
		input.close();
		output.close();	
	} catch (const std::exception &err) {
		std::cout << "An error occured:\n\t" << err.what() << std::endl;
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}
