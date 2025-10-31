/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 18:38:07 by malaamir          #+#    #+#             */
/*   Updated: 2025/10/28 15:04:25 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip>
#include <sstream>
#include <string>
#include <cstdlib>

class PhoneBook
{
private:
	Contact	contacts[8];
	int		next_index;
	void printFormattedField(const std::string& field) const;

public:

	PhoneBook();
	~PhoneBook();
	
	void addContact();
	void searchContact() const;

};
#endif