/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 15:49:48 by malaamir          #+#    #+#             */
/*   Updated: 2025/11/16 10:32:29 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(const std::string &name) : name(name)
{
	std::cout << GREEN << "Character parameterized constructor called" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
		inventory[i] = 0;
}

Character::Character(const Character &other) : name(other.name)
{
	std::cout << GREEN << "Character copy constructor called" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (other.inventory[i])
			inventory[i] = other.inventory[i]->clone();
		else
			inventory[i] = 0;
	}
}

Character &Character::operator=(const Character &other)
{
	std::cout << GREEN << "Character copy assignment operator called" << RESET << std::endl;

	if (this != &other)
	{
		this->name = other.name;
		for (int i = 0; i < 4; i++)
		{
			if (inventory[i])
			{
				delete inventory[i];
				inventory[i] = 0;
			}
			if (other.inventory[i])
				inventory[i] = other.inventory[i]->clone();
		}
	}

	return *this;
}

Character::~Character()
{
	std::cout << RED << "Character destructor called" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i])
		{
			delete inventory[i];
			inventory[i] = 0;
		}
	}
}

std::string const &Character::getName() const
{
	return this->name;
}

void Character::equip(AMateria *m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (!inventory[i])
		{
			inventory[i] = m;
			std::cout << "Equipped " << m->getType() << " in slot " << i << std::endl;
			return;
		}
	}
	std::cout << "Inventory full, cannot equip " << m->getType() << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
	{
		std::cout << "Invalid index to unequip: " << idx << std::endl;
		return;
	}
	if (inventory[idx])
	{
		std::cout << "Unequipped " << inventory[idx]->getType() << " from slot " << idx << std::endl;
		inventory[idx] = NULL;
	}
	else
	{
		std::cout << "No materia to unequip in slot " << idx << std::endl;
	}
}

void Character::use(int idx, ICharacter &target)
{
	
	if (idx < 0 || idx >= 4)
	{
		std::cout << "Invalid index to use: " << idx << std::endl;
		return;
	}
	if (inventory[idx])
	{
		inventory[idx]->use(target);
	}
	else
	{
		std::cout << "No materia to use in slot " << idx << std::endl;
	}
}
