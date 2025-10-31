/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:57:14 by malaamir          #+#    #+#             */
/*   Updated: 2025/10/31 15:09:51 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon
{
private :
	std::string type;
	
public :
	Weapon(std::string type);
	~Weapon();
	
	const std::string& gettype() const;
	void settype(std::string type);
};

#endif