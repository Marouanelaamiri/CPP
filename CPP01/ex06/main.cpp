/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 16:13:56 by malaamir          #+#    #+#             */
/*   Updated: 2025/11/01 17:17:25 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error : Wrong number of arguments" << std::endl;
		return 1;
	}
	Harl harl;
	std::string Levels[4] = {"DEBUG", "INFO" , "WARNING", "ERROR"};
	
	std::string inputlvl = av[1];
	int indexlevel = -1;

	for(int i = 0; i < 4; i++)
	{
		if(inputlvl == Levels[i])
		{
			indexlevel = i;
			break;
		}
	}
	
	switch(indexlevel)
	{
		case 0:
			harl.complain("DEBUG");
			// fall through
		case 1:
			harl.complain("INFO");
			// fall through
		case 2:
			harl.complain("WARNING");
			// fall through
		case 3:
			harl.complain("ERROR");
			break;

		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
	return 0;
}