/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 18:41:51 by malaamir          #+#    #+#             */
/*   Updated: 2025/10/28 15:04:55 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	next_index = 0;
	std::cout << "PhoneBook Constructor called" << std::endl;
}
PhoneBook::~PhoneBook()
{
	std::cout << "PhoneBook Destructor called" << std::endl;
}

std::string getValidatedInput(const std::string& prompt)
{
    std::string input;
    while (true)
	{
		std::cout << prompt;
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << "\nExiting." << std::endl;
			exit(0);
		}
		if (!input.empty())
			return input;
		std::cout << "NOP you cant put an empty field." << std::endl;
	}
}

void PhoneBook::addContact()
{
    Contact newContact;

    newContact.setFirstName(getValidatedInput("Enter first name: "));
    newContact.setLastName(getValidatedInput("Enter last name: "));
    newContact.setNickname(getValidatedInput("Enter nickname: "));
    newContact.setPhoneNumber(getValidatedInput("Enter phone number: "));
    newContact.setDarkestSecret(getValidatedInput("Enter darkest secret: "));

    contacts[next_index] = newContact;
	next_index = (next_index + 1) % 8;
	if(next_index == 0)
		std::cout << "PhoneBook is full. Overwriting oldest contact." << std::endl;
    std::cout << "Contact added successfully!" << std::endl;
}

void PhoneBook::printFormattedField(const std::string& field) const
{
	if (field.length() > 10)
		std::cout << std::right << std::setw(10) << field.substr(0, 9) + ".";
	else
		std::cout << std::right << std::setw(10) << field;
}

void PhoneBook::searchContact() const
{
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|" << std::right << std::setw(10) << "Index" 
			  << "|" << std::right << std::setw(10) << "First Name" 
			  << "|" << std::right << std::setw(10) << "Last Name" 
			  << "|" << std::right << std::setw(10) << "Nickname" 
			  << "|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	
	for (int i = 0; i < 8; i++)
	{	
		std::cout << "|"  << std::right << std::setw(10) << i << "|";
			printFormattedField(contacts[i].getFirstName());
		std::cout << "|";
			printFormattedField(contacts[i].getLastName());
		std::cout << "|";
			printFormattedField(contacts[i].getNickname());
		std::cout << "|" << std::endl;
	}
	
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "Enter contact index to view details: ";
	std::string input;
	std::getline(std::cin, input);
	
	int index;
	std::stringstream ss(input);
	if (ss >> index && ss.eof())
	{
		if(index < 0 || index >= 8 || contacts[index].getFirstName().empty())
		{
			std::cout << "Invalid index. No contact found." << std::endl;
			return;
		}
		std::cout << "Contact Details:" << std::endl;
		std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
		std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
		std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
		std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
		std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
	}
	else
		std::cout << "Invalid input. Please enter a valid index." << std::endl;
}