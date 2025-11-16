/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 15:47:26 by malaamir          #+#    #+#             */
/*   Updated: 2025/11/16 10:32:42 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << GREEN << "Cure default constructor called" << RESET << std::endl;
}

Cure::Cure(const Cure &other) : AMateria(other)
{
	std::cout << GREEN << "Cure copy constructor called" << RESET << std::endl;
}

Cure &Cure::operator=(const Cure &other)
{
	std::cout << GREEN << "Cure copy assignment operator called" << RESET << std::endl;

	if (this != &other)
		AMateria::operator=(other);

	return *this;
}

Cure::~Cure()
{
	std::cout << RED << "Cure destructor called" << RESET << std::endl;
}

AMateria *Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
