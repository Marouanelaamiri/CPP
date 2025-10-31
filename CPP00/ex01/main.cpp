/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 18:44:51 by malaamir          #+#    #+#             */
/*   Updated: 2025/10/27 18:10:54 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook phoneBook;
	std::string command;

	std::cout << "Welcome to the PhoneBook application!" << std::endl;
	while (true)
	{
		std::cout << "Please enter a command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);
		if (std::cin.eof())
		{
			std::cout << "\nExiting." << std::endl;
			break;
		}
		if (command == "ADD")
			phoneBook.addContact();
		else if (command == "SEARCH")
			phoneBook.searchContact();
		else if (command == "EXIT")
		{
			std::cout << "Exiting the PhoneBook application. Goodbye!" << std::endl;
			break;
		}
		else
			std::cout << "Invalid command. Please try again." << std::endl;
	}
	return 0;
}