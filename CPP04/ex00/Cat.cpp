/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:28:31 by malaamir          #+#    #+#             */
/*   Updated: 2025/11/14 14:58:34 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}
Cat::Cat(const Cat& original) : Animal(original)
{
	std::cout << "Cat copy constructor called" << std::endl;
}
Cat& Cat::operator=(const Cat& original)
{
	std::cout << "Cat copy assignment operator called" << std::endl;

	if (this != &original)
		Animal::operator=(original);

	return *this;
}
Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}
void Cat::makeSound() const
{
	std::cout << "Meow Meow!" << std::endl;
}
