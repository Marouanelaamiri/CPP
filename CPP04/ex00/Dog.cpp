/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:28:16 by malaamir          #+#    #+#             */
/*   Updated: 2025/11/14 14:58:29 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
Dog::Dog() : Animal()
{
	this->type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}
Dog::Dog(const Dog& original) : Animal(original)
{
	std::cout << "Dog copy constructor called" << std::endl;
}
Dog& Dog::operator=(const Dog& original)
{
	std::cout << "Dog copy assignment operator called" << std::endl;

	if (this != &original)
		Animal::operator=(original);

	return *this;
}
Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}
void Dog::makeSound() const
{
	std::cout << "Woof Woof!" << std::endl;
}