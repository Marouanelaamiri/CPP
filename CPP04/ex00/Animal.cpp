/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:27:58 by malaamir          #+#    #+#             */
/*   Updated: 2025/11/14 12:09:00 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}
Animal::Animal(const Animal &original) : type(original.type)
{
	std::cout << "Animal copy constructor called" << std::endl;
}
Animal &Animal::operator=(const Animal &original)
{
	std::cout << "Animal copy assignment operator called" << std::endl;

	if (this != &original)
		this->type = original.type;

	return *this;
}
Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}
void Animal::makeSound() const
{
	std::cout << "Animal sound" << std::endl;
}
std::string Animal::getType() const
{
	return this->type;
}
