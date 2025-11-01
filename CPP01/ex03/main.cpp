/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:57:02 by malaamir          #+#    #+#             */
/*   Updated: 2025/11/01 15:21:46 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main()
{
    {
        // HumanA test
        Weapon weapon = Weapon("Zarwata mli7a");

        // 'romani' is created with his weapon directly.
        // You cannot create a HumanA without a weapon. // why ? because reference must be initialized when declared
        HumanA Human1("Romani", weapon);
        Human1.attack();

        // The weapon's type is changed.
        weapon.settype("7ajra");

        // romani's weapon changes too, because he holds a reference to 'zarwata'.
        Human1.attack();
    }
    {
        // HumanB test
        Weapon weapon = Weapon("9ar3a dial jaj");

        // 'badr' is created without a weapon.
        HumanB Human2("Badr");

        // badr attacks with bare hands because his weapon pointer is NULL.
        Human2.attack();

        // badr is given a weapon.
        Human2.setweapon(weapon);
        Human2.attack();

        // The weapon's type is changed.
        weapon.settype("7ajra kbiiiiira");

        // badr's weapon also changes.
        Human2.attack();
    }
    return 0;
}