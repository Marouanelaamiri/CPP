/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 18:26:52 by malaamir          #+#    #+#             */
/*   Updated: 2025/10/26 16:51:56 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	std::cout << "Contact Constructor called" << std::endl;	
}
Contact::~Contact()
{
	std::cout << "Contact Destructor called" << std::endl;
}


void Contact::setFirstName(const std::string& fname) { firstName = fname; }
void Contact::setLastName(const std::string& lname) { lastName = lname; }
void Contact::setNickname(const std::string& nname) { nickname = nname; }
void Contact::setPhoneNumber(const std::string& pnumber) { phoneNumber = pnumber; }
void Contact::setDarkestSecret(const std::string& secret) { darkestSecret = secret; }

std::string	Contact::getFirstName() const {return firstName;}
std::string	Contact::getLastName() const {return lastName;}
std::string	Contact::getNickname() const {return nickname;}
std::string	Contact::getPhoneNumber() const {return phoneNumber;}
std::string	Contact::getDarkestSecret() const {return darkestSecret;}
