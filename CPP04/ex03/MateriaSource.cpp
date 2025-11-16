/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 15:56:57 by malaamir          #+#    #+#             */
/*   Updated: 2025/11/16 10:33:14 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << GREEN << "MateriaSource default constructor called" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
		materiaSlots[i] = NULL;
}
MateriaSource::MateriaSource(const MateriaSource &other)
{
	std::cout << GREEN << "MateriaSource copy constructor called" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (other.materiaSlots[i])
			materiaSlots[i] = other.materiaSlots[i]->clone();
		else
			materiaSlots[i] = NULL;
	}
}
MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	std::cout << GREEN << "MateriaSource copy assignment operator called" << RESET << std::endl;

	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (materiaSlots[i])
			{
				delete materiaSlots[i];
				materiaSlots[i] = NULL;
			}
			if (other.materiaSlots[i])
				materiaSlots[i] = other.materiaSlots[i]->clone();
		}
	}

	return *this;
}

MateriaSource::~MateriaSource()
{
	std::cout << RED << "MateriaSource destructor called" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (materiaSlots[i])
		{
			delete materiaSlots[i];
			materiaSlots[i] = NULL;
		}
	}
}

void MateriaSource::learnMateria(AMateria *m) // setter
{
	for (int i = 0; i < 4; i++)
	{
		if (materiaSlots[i] == NULL)
		{
			materiaSlots[i] = m;
			std::cout << "Learned materia of type: " << m->getType() << " in slot " << i << std::endl;
			return;
		}
	}
	std::cout << "MateriaSource is full, cannot learn more materia." << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type) // getter
{
	for (int i = 0; i < 4; i++)
	{
		if (materiaSlots[i] && materiaSlots[i]->getType() == type)
		{
			std::cout << "Creating materia of type: " << type << std::endl;
			return materiaSlots[i]->clone();
		}
	}
	std::cout << "Materia of type: " << type << " not found." << std::endl;
	return NULL;
}
