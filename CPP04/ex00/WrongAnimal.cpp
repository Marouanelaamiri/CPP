/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:29:46 by malaamir          #+#    #+#             */
/*   Updated: 2025/11/14 12:08:00 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& original) : type(original.type)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& original)
{
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	if (this != &original)
		this->type = original.type;

	return *this;
}
WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal sound!" << std::endl;
}
std::string WrongAnimal::getType() const
{
	return this->type;
}
