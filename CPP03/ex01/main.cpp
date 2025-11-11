/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:16:12 by malaamir          #+#    #+#             */
/*   Updated: 2025/11/11 10:16:11 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
    std::cout << "--- 1. CREATING SCAVTRAP 'ROBOCOP' (100 HP, 50 EP) ---" << std::endl;
    ScavTrap scav("Robocop");

    std::cout << "\n--- 2. TESTING HEAVY DAMAGE ---" << std::endl;
    scav.takeDamage(90); // HP: 10/100
    scav.attack("Criminal"); // HP: 10/100, EP: 49/50

    std::cout << "\n--- 3. TESTING REPAIR ---" << std::endl;
    scav.beRepaired(5); // HP: 15/100, EP: 48/50

    std::cout << "\n--- 4. TESTING FATAL DAMAGE (EXACTLY 100 TOTAL) ---" << std::endl;
    // (90 damage + 15 damage = 105 total damage, but it had 5 repair)
    // (Total HP lost: 90 - 5 + 15 = 100)
    scav.takeDamage(15); // HP: 0/100

    std::cout << "\n--- 5. TESTING ACTIONS AFTER DESTRUCTION (0 HP) ---" << std::endl;
    // All actions should fail now
    scav.attack("A Ghost");
    scav.beRepaired(50);
    scav.guardGate();

    std::cout << "\n--- 6. TEST COMPLETE ---" << std::endl;
    return 0; // 'Robocop' destructor will be called here
}