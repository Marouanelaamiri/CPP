/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:16:12 by malaamir          #+#    #+#             */
/*   Updated: 2025/11/11 11:18:11 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void)
{
	std::cout << "--- 1. CREATING FRAGTRAP 'FRAGGY' (100 HP, 100 EP, 30 AD) ---" << std::endl;
	// Constructor chain: ClapTrap -> FragTrap
	FragTrap fraggy("Fraggy");

	std::cout << "\n--- 2. TESTING ATTACK (30 AD) & HIGH FIVES ---" << std::endl;
	fraggy.attack("a bandit"); // Should use 30 AD, EP: 99
	fraggy.highFivesGuys();	   // Test the new function

	std::cout << "\n--- 3. TESTING 100 HP LIMIT ---" << std::endl;
	fraggy.takeDamage(90); // HP: 10/100
	fraggy.beRepaired(10); // HP: 20/100, EP: 98
	fraggy.takeDamage(19); // HP: 1/100
	fraggy.takeDamage(1);  // HP: 0/100 (Destroyed)

	std::cout << "\n--- 4. TESTING ACTIONS AFTER 0 HP ---" << std::endl;
	fraggy.attack("a ghost"); // Should fail
	fraggy.beRepaired(50);	  // Should fail
	fraggy.highFivesGuys();	  // Should also fail (if it checks HP)

	std::cout << "\n---------------------------------" << std::endl;
	std::cout << "--- 5. TESTING 100 EP LIMIT ---" << std::endl;
}