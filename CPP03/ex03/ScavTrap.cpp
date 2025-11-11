/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:21:01 by malaamir          #+#    #+#             */
/*   Updated: 2025/11/11 11:15:54 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << "ScavTrap " << this->name << " created" << std::endl;
	this->hitpoints = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
}
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap " << this->name << " created" << std::endl;
	this->hitpoints = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
}
ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = other;
}
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);

	return (*this);
}
ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << this->name << " destructor called" << std::endl;
}
void ScavTrap::attack(const std::string &target)
{
	if (this->energy_points > 0 && this->hitpoints > 0)
	{
		this->energy_points--;
		std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
	}
	else
	{
		std::cout << "ScavTrap " << this->name << " has no energy points or hitpoints left to attack!" << std::endl;
	}
}

void ScavTrap::guardGate()
{
	if (this->hitpoints <= 0)
	{
		std::cout << "ScavTrap " << this->name << " cannot enter Gate Keeper mode because it has no hitpoints left!" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << this->name << " has entered Gate Keeper mode!" << std::endl;
}
