/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:20:01 by malaamir          #+#    #+#             */
/*   Updated: 2025/11/12 18:00:15 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("Default_clap_name"), name("Default")
{
	std::cout << "DiamondTrap " << this->name << " created" << std::endl;
	this->hitpoints = FragTrap::hitpoints;
	this->attack_damage = FragTrap::attack_damage;
	this->energy_points = 50;
}

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) ,name(name)
{
	std::cout << "DiamondTrap " << this->name << " created" << std::endl;
	hitpoints = FragTrap::hitpoints;
	attack_damage = FragTrap::attack_damage;
	energy_points = 50;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = other;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);

	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->name << " destructor called" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "im a DiamondTrap named " << name << " and my ClapTrap name is " << ClapTrap::name << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}
