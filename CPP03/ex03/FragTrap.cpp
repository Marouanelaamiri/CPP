/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:15:11 by malaamir          #+#    #+#             */
/*   Updated: 2025/11/11 17:24:38 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"


FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap " << this->name << " created" << std::endl;
	hitpoints = 100;
	energy_points = 100;
	attack_damage = 30;
}
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap " << this->name << " created" << std::endl;
	hitpoints = 100;
	energy_points = 100;
	attack_damage = 30;
}
FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);
}
FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->name << " destructor called" << std::endl;
}

void FragTrap::highFivesGuys()
{
	if (this->hitpoints > 0)
		std::cout << "FragTrap " << this->name << " cmon bro high five! ✋" << std::endl;
	else
		std::cout << "FragTrap " << this->name << " is out of hitpoints and cannot request a high five!" << std::endl;
}