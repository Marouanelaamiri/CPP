/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 18:08:38 by malaamir          #+#    #+#             */
/*   Updated: 2025/10/26 16:51:52 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>

class Contact
{
private:
	//member funnctions
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	darkestSecret;
;
public:
	//constructor
	Contact();
	//destructor
	~Contact();
	//setters
	void	setFirstName(const std::string& fname);
	void	setLastName(const std::string& lname);
	void	setNickname(const std::string& nname);
	void	setPhoneNumber(const std::string& pnumber);
	void	setDarkestSecret(const std::string& secret);
	//getters
	std::string	getFirstName() const;
	std::string	getLastName() const;
	std::string	getNickname() const;
	std::string	getPhoneNumber() const;
	std::string	getDarkestSecret() const;
};


#endif