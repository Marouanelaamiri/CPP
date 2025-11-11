/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:17:20 by malaamir          #+#    #+#             */
/*   Updated: 2025/11/11 17:45:36 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main(void)
{
	std::cout << "--- 1. CONSTRUCTING 'DIAMO' ---" << std::endl;
	// Constructor chain: ClapTrap -> ScavTrap -> FragTrap -> DiamondTrap
	DiamondTrap diamond("Diamo");

	std::cout << "\n--- 2. TESTING whoAmI() ---" << std::endl;
	// Should print "Diamo" and "Diamo_clap_name"
	diamond.whoAmI();

	std::cout << "\n--- 3. TESTING ABILITIES ---" << std::endl;
	// Should use ScavTrap::attack (50 EP) but with FragTrap's 30 AD
	diamond.attack("a target"); // EP: 49/50, AD: 30
	diamond.guardGate();		// From ScavTrap
	diamond.highFivesGuys();	// From FragTrap

	std::cout << "\n--- 4. TESTING STATS (100 HP, 50 EP) ---" << std::endl;
	diamond.takeDamage(90); // HP: 10/100 (from FragTrap)
	diamond.beRepaired(10); // HP: 20/100, EP: 48/50
	diamond.takeDamage(20); // HP: 0/100 (Destroyed)

	std::cout << "\n--- 5. TESTING ACTIONS AFTER 0 HP ---" << std::endl;
	diamond.attack("a ghost"); // Should fail
	diamond.beRepaired(10);	   // Should fail
	diamond.guardGate();	   // Should fail
	diamond.highFivesGuys();   // Should fail

	std::cout << "\n--- 7. TESTING ACTIONS AFTER 0 EP ---" << std::endl;
	diamond.attack("one more"); // Should fail
	diamond.beRepaired(10);		// Should fail

	std::cout << "\n---------------------------------" << std::endl;
	std::cout << "\n--- 9. TEST COMPLETE (DESTRUCTION) ---" << std::endl;
	// Destructor chain: DiamondTrap -> FragTrap -> ScavTrap -> ClapTrap
	return 0;
}