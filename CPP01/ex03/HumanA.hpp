/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:57:39 by malaamir          #+#    #+#             */
/*   Updated: 2025/10/31 16:02:40 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
private :
	std::string name;
	Weapon& weapon; // an alias reference to a Weapon object
	
public :
	HumanA(std::string name, Weapon& weapon);
	~HumanA();

	void attack();
};

#endif