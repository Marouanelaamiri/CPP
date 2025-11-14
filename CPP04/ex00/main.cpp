/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:22:36 by malaamir          #+#    #+#             */
/*   Updated: 2025/11/14 12:40:05 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	// --- Test 1: Correct Virtual Polymorphism ---
	std::cout << "--- 1. TESTING VIRTUAL (CORRECT) ---" << std::endl;
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	std::cout << "---------------------------------" << std::endl;

	// Test getType()
	std::cout << "Pointer 'j' has type: " << j->getType() << " " << std::endl;		 // Should be Dog
	std::cout << "Pointer 'i' has type: " << i->getType() << " " << std::endl;		 // Should be Cat
	std::cout << "Pointer 'meta' has type: " << meta->getType() << " " << std::endl; // Should be Animal

	std::cout << "---------------------------------" << std::endl;

	// Test makeSound() - Dynamic Polymorphism
	// These MUST call the child's (Dog/Cat) sound
	std::cout << "Pointer 'i' (a Cat) makes sound: ";
	i->makeSound();
	std::cout << "Pointer 'j' (a Dog) makes sound: ";
	j->makeSound();
	std::cout << "Pointer 'meta' (an Animal) makes sound: ";
	meta->makeSound();

	std::cout << "---------------------------------" << std::endl;

	// Test Destruction
	std::cout << "Deleting meta..." << std::endl;
	delete meta;
	std::cout << "Deleting j (Dog)..." << std::endl;
	delete j;
	std::cout << "Deleting i (Cat)..." << std::endl;
	delete i;

	std::cout << "\n\n--- 2. TESTING NON-VIRTUAL (WRONG) ---" << std::endl;
	const WrongAnimal *wrongMeta = new WrongAnimal();
	const WrongAnimal *wrongI = new WrongCat();

	std::cout << "---------------------------------" << std::endl;

	// // Test getType()
	std::cout << "Pointer 'wrongI' has type: " << wrongI->getType() << " " << std::endl;	   // Should be WrongCat
	std::cout << "Pointer 'wrongMeta' has type: " << wrongMeta->getType() << " " << std::endl; // Should be WrongAnimal

	std::cout << "---------------------------------" << std::endl;

	// // Test makeSound() - Static Polymorphism
	// // This will FAIL to call the child's sound
	std::cout << "Pointer 'wrongI' (a WrongCat) makes sound: ";
	wrongI->makeSound(); // This will call WrongAnimal's sound!
	std::cout << "Pointer 'wrongMeta' (a WrongAnimal) makes sound: ";
	wrongMeta->makeSound();

	std::cout << "---------------------------------" << std::endl;

	// // This is to prove the WrongCat's sound function *does* exist,
	// but isn't called by the parent pointer.
	std::cout << "--- TESTING WRONGCAT DIRECTLY ---" << std::endl;
	WrongCat *directWrongCat = new WrongCat();
	std::cout << "Direct WrongCat makes sound: ";
	directWrongCat->makeSound(); // This WILL call the WrongCat sound.
	delete directWrongCat;

	std::cout << "---------------------------------" << std::endl;

	// Sizeof tests to show v-table overhead
	std::cout << "Size of WrongAnimal (no v-table): " << sizeof(WrongAnimal) << std::endl;
	std::cout << "Size of Animal (has v-table): " << sizeof(Animal) << std::endl;
	
	std::cout << "---------------------------------" << std::endl;
	// // Test Destruction
	std::cout << "Deleting wrongMeta..." << std::endl;
	delete wrongMeta;
	std::cout << "Deleting wrongI (WrongCat)..." << std::endl;
	delete wrongI;

	return 0;
}