/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:28:31 by malaamir          #+#    #+#             */
/*   Updated: 2025/11/14 15:22:54 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat default constructor called" << std::endl;
	brains = new Brain();
	this->type = "Cat";
}
Cat::Cat(const Cat &original) : Animal(original)
{
	std::cout << "Cat copy constructor called" << std::endl;
	brains = new Brain(*original.brains);
}
Cat &Cat::operator=(const Cat &original)
{
	std::cout << "Cat copy assignment operator called" << std::endl;

	if (this != &original)
	{
		Animal::operator=(original);
		*brains = *original.brains;
		// brains = original.brains;
	}
	return *this;
}
Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete brains;
}
void Cat::makeSound() const
{
	std::cout << "Meow Meow!" << std::endl;
}

Brain *Cat::getBrain() const
{
	return brains;
}