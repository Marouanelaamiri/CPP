/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 16:20:30 by malaamir          #+#    #+#             */
/*   Updated: 2025/11/01 15:50:41 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(int ac, char **av)
{
	if(ac == 4)
	{
		std::string filename = av[1];
		std::string s1 = av[2];
		std::string s2 = av[3];
		
		if(s1.empty()) // check if s1 is empty
		{
			std::cerr << "Error : string to be replaced cant be empty." << std::endl;
			return 1;
		}
		std::ifstream inputfile(filename.c_str()); // open the input file
		if (!inputfile.is_open()) // check if the file is can be open
		{
			std::cerr << "Error : cant open input file " << filename << std::endl ;
			return 1;
		}
		std::ofstream outputfile((filename + ".replace").c_str()); // create and open the output file c_str is used to convert string to const char*
		if(!outputfile.is_open()) // check if the output file is can be open
		{
			std::cerr << "Error : cant create output file " << filename << std::endl ;
			return 1;
		}
		std::string line; // to store each line
		while (std::getline(inputfile, line)) // read the file line by line
		{
			size_t pos = 0;
			while ((pos = line.find(s1 ,pos)) != std::string::npos) // find s1 in the line
			{
				line.erase(pos, s1.length()); // remove s1 from the line
				line.insert(pos, s2); // insert s2 in the line
				pos += s2.length(); // move pos forward
			}
			outputfile << line; // write the modified line to the output file
		}
	}
	else // wrong number of arguments
	{
		std::cerr << "Error : Wrong number of arguments" << std::endl;
		return 1;
	}
	return 0;
}