/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 15:37:18 by malaamir          #+#    #+#             */
/*   Updated: 2025/11/16 10:31:59 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : type("default")
{
	std::cout << GREEN << "AMateria default constructor called" << RESET << std::endl;
}
AMateria::AMateria(const std::string &type) : type(type)
{
	std::cout << GREEN << "AMateria parameterized constructor called" << RESET << std::endl;
}
AMateria::AMateria(const AMateria &other) : type(other.type)
{
	std::cout << GREEN << "AMateria copy constructor called" << RESET << std::endl;
}

AMateria &AMateria::operator=(const AMateria &other)
{
	std::cout << GREEN << "AMateria copy assignment operator called" << RESET << std::endl;
	(void)other;
	return *this;
}

AMateria::~AMateria()
{
	std::cout << RED << "AMateria destructor called" << RESET << std::endl;
}

std::string const &AMateria::getType() const
{
	return this->type;
}

void AMateria::use(ICharacter &target)
{
	std::cout << "* uses " << this->type << " on " << target.getName() << " *" << std::endl;
}