/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 15:46:26 by malaamir          #+#    #+#             */
/*   Updated: 2025/11/16 10:32:55 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << GREEN << "Ice default constructor called" << RESET << std::endl;
}
Ice::Ice(const Ice &other) : AMateria(other)
{
	std::cout << GREEN << "Ice copy constructor called" << RESET << std::endl;
}
Ice &Ice::operator=(const Ice &other)
{
	std::cout << GREEN << "Ice copy assignment operator called" << RESET << std::endl;

	if (this != &other)
		AMateria::operator=(other);

	return *this;
}
Ice::~Ice()
{
	std::cout << RED << "Ice destructor called" << RESET << std::endl;
}
AMateria *Ice::clone() const
{
	return new Ice(*this);
}
void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}