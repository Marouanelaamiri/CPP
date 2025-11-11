/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:16:12 by malaamir          #+#    #+#             */
/*   Updated: 2025/11/11 10:06:47 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
    std::cout << "--- 1. TESTING CLAPPY (10 HP LIMIT) ---" << std::endl;
    ClapTrap clappy("Clappy"); // Spawns with 10 HP, 10 EP

    // Test attack and repair
    clappy.attack("a target");  // EP: 9
    clappy.beRepaired(5);       // EP: 8, HP: 15 (assuming no HP cap)
    
    // Test taking damage
    clappy.takeDamage(3);       // HP: 12
    clappy.takeDamage(12);      // HP: 0 (should be destroyed here)

    // Test actions after destruction (0 HP)
    std::cout << "\n--- CLAPPY SHOULD BE DESTROYED, TESTING ACTIONS ---" << std::endl;
    clappy.takeDamage(5);   // Should fail
    clappy.beRepaired(10);  // Should fail
    clappy.attack("a ghost"); // Should fail

    std::cout << "\n---------------------------------" << std::endl;
    std::cout << "--- 2. TESTING ZAPPY (10 EP LIMIT) ---" << std::endl;

    ClapTrap energyboy("Zappy"); // Spawns with 10 HP, 10 EP

    // Drain 5 energy points
    energyboy.attack("Psycho"); // EP: 9
    energyboy.attack("Psycho"); // EP: 8
    energyboy.attack("Psycho"); // EP: 7
    energyboy.attack("Psycho"); // EP: 6
    energyboy.attack("Psycho"); // EP: 5

    // Drain the other 5 energy points
    energyboy.beRepaired(2); // EP: 4
    energyboy.beRepaired(2); // EP: 3
    energyboy.beRepaired(2); // EP: 2
    energyboy.beRepaired(2); // EP: 1
    energyboy.beRepaired(2); // EP: 0 (should have no energy points left here)

    // Test actions after 0 energy
    std::cout << "\n--- ZAPPY SHOULD BE OUT OF ENERGY, TESTING ACTIONS ---" << std::endl;
    energyboy.attack("Psycho");   // Should fail
    energyboy.beRepaired(10); // Should fail
    energyboy.takeDamage(3);  // Should still work (taking damage costs no energy)

    std::cout << "\n---------------------------------" << std::endl;
    std::cout << "--- 3. TEST COMPLETE ---" << std::endl;
    
    return 0; // Destructors for clappy and energyboy called here
}