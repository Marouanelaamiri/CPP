/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:58:04 by malaamir          #+#    #+#             */
/*   Updated: 2025/10/31 16:03:35 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
private :
	std::string name;
	Weapon* weapon; // a pointer to a Weapon object ( can be NULL )

public :
	HumanB(std::string name);
	~HumanB();

	void setweapon(Weapon& weapon);
	void attack();
};

#endif