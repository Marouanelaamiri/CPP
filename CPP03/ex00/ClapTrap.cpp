/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:18:09 by malaamir          #+#    #+#             */
/*   Updated: 2025/11/11 10:03:05 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : name("Default"), hitpoints(10), energy_points(10), attack_damage(0)
{
	std::cout << "ClapTrap " << this->name << " created" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitpoints(10), energy_points(10), attack_damage(0)
{
	std::cout << "ClapTrap " << this->name << " created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "ClapTrap copy constroctur called" << std::endl;
	*this = other;
}
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->name = other.name;
		this->hitpoints = other.hitpoints;
		this->energy_points = other.energy_points;
		this->attack_damage = other.attack_damage;
	}
	return (*this);
}
ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << this->name << " destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->energy_points > 0 && this->hitpoints > 0)
	{
		this->energy_points--;
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << this->name << " has no energy points or hitpoints left to attack!" << std::endl;
	}
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energy_points > 0 && this->hitpoints > 0)
	{
		this->energy_points--;
		this->hitpoints += amount;
		std::cout << "ClapTrap " << this->name << " repairs itself, regaining " << amount << " hitpoints!" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << this->name << " has no energy points or hitpoints left to repair!" << std::endl;
	}
}
void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitpoints > 0)
	{
		if (amount >= this->hitpoints)
			this->hitpoints = 0;
		else
			this->hitpoints -= amount;
		std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!, remaining hitpoints: " << this->hitpoints << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << this->name << " has no hitpoints left to take damage!" << std::endl;
	}
}
