/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:58:22 by malaamir          #+#    #+#             */
/*   Updated: 2025/10/31 15:35:15 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) :name(name) , weapon(NULL) {}
HumanB::~HumanB() {}

void HumanB::setweapon(Weapon& weapon) {this->weapon = &weapon;}
void HumanB::attack() 
{
	if(this->weapon)
		std::cout << this->name << " attack with " << this->weapon->gettype()<< std::endl ;
	else
		std::cout << this->name << " attacks with BONKA" << std::endl ;
}
