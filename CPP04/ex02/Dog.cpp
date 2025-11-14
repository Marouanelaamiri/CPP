/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:28:16 by malaamir          #+#    #+#             */
/*   Updated: 2025/11/14 17:49:36 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
Dog::Dog() : Animal()
{
	std::cout << "Dog default constructor called" << std::endl;
	brains = new Brain();
	this->type = "Dog";
}
Dog::Dog(const Dog &original) : Animal(original)
{
	std::cout << "Dog copy constructor called" << std::endl;
	brains = new Brain(*original.brains);
}
Dog &Dog::operator=(const Dog &original)
{
	std::cout << "Dog copy assignment operator called" << std::endl;

	if (this != &original)
	{
		Animal::operator=(original);
		*brains = *original.brains;
		// brains = original.brains;
	}
	return *this;
}
Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete brains;
}
void Dog::makeSound() const
{
	std::cout << "Woof Woof!" << std::endl;
}

Brain *Dog::getBrain() const
{
	return brains;
}