/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 16:20:30 by malaamir          #+#    #+#             */
/*   Updated: 2025/10/31 16:59:00 by malaamir         ###   ########.fr       */
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
		
		if(s1.empty())
		{
			std::cerr << "Error : string to be replaced cant be empty." << std::endl;
			return 1;
		}
		std::ifstream inputfile(filename.c_str());
		if (!inputfile.is_open())
		{
			std::cerr << "Error : cant open input file " << filename << std::endl ;
			return 1;
		}
		std::ofstream outputfile((filename + ".replace").c_str());
		if(!outputfile.is_open())
		{
			std::cerr << "Error : cant create input file " << filename << std::endl ;
			inputfile.close();
			return 1;
		}
		std::string line;
		while (std::getline(inputfile, line))
		{
			size_t pos = 0;
			while ((pos = line.find(s1 ,pos)) != std::string::npos)
			{
				line.erase(pos, s1.length());
				line.insert(pos, s2);
				pos += s2.length();
			}
			outputfile << line;
			
			if(!inputfile.eof())
				outputfile << std::endl;
		}
	}
	else
	{
		std::cerr << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
		return 1;
	}
	return 0;
}