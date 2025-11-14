/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:17:12 by malaamir          #+#    #+#             */
/*   Updated: 2025/11/14 17:46:10 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}
Brain::Brain(const Brain& other)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = other;
}
Brain& Brain::operator=(const Brain& other)
{
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; ++i)
		{
			this->ideas[i] = other.ideas[i];
		}
	}
	return *this;
}
Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

void Brain::set_idea(int index, const std::string& idea)
{
	if (index >= 0 && index < 100)
	{
		ideas[index] = idea;
	}
}

std::string Brain::get_idea(int index) const
{
	if (index >= 0 && index < 100)
	{
		return ideas[index];
	}
	return "ERROR: Index out of bounds";
}

