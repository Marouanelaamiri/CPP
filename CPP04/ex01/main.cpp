/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:48:39 by malaamir          #+#    #+#             */
/*   Updated: 2025/11/14 15:08:36 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
    // --- 1. TESTING ANIMAL ARRAY & VIRTUAL DESTRUCTORS ---
    std::cout << "--- 1. TESTING ANIMAL ARRAY & VIRTUAL DESTRUCTORS ---" << std::endl;
	
    const int arraySize = 100;
    Animal* animals[arraySize];
	
    std::cout << "--- Filling array... ---" << std::endl;
    for (int i = 0; i < arraySize / 2; i++)
    {
        animals[i] = new Dog();
        std::cout << "Created " << animals[i]->getType() << " " << i << std::endl;
    }
	
    for (int i = arraySize / 2; i < arraySize; i++)
    {
        animals[i] = new Cat();
        std::cout << "Created " << animals[i]->getType() << " " << i << std::endl;
    }
	
    std::cout << "\n--- Deleting array... ---" << std::endl;
    for (int i = 0; i < arraySize; i++)
    {
        std::cout << "Deleting " << animals[i]->getType() << "..." << std::endl;
        delete animals[i];
    }

    // --- 2. TESTING DEEP COPY (CONSTRUCTOR) ---
    std::cout << "\n\n--- 2. TESTING DEEP COPY (CONSTRUCTOR) ---" << std::endl;
    
    std::cout << "--- Creating 'originalDog' and setting idea... ---" << std::endl;
    Dog originalDog;
    originalDog.getBrain()->set_idea(0, "I am the original dog.");

    std::cout << "--- Creating 'copiedDog = originalDog'... ---" << std::endl;
    Dog copiedDog = originalDog; 

    std::cout << "\n--- Modifying 'copiedDog's brain... ---" << std::endl;
    copiedDog.getBrain()->set_idea(0, "I am the copy.");

    std::cout << "\n--- Checking brains to prove independence... ---" << std::endl;
    std::cout << "  Original Dog's idea: " << originalDog.getBrain()->get_idea(0) << std::endl;
    std::cout << "  Copied Dog's idea:   " << copiedDog.getBrain()->get_idea(0) << std::endl;

    // Check if the original's idea was changed.
    if (originalDog.getBrain()->get_idea(0) == "I am the original dog.")
    {
        std::cout << "  (Test PASSED: Original dog is unchanged. Copy was deep.)" << std::endl;
    }
    else
    {
        std::cout << "  (Test FAILED: Original dog's brain was overwritten! Copy was shallow.)" << std::endl;
    }


    // --- 3. TESTING DEEP COPY (ASSIGNMENT) ---
    std::cout << "\n\n--- 3. TESTING DEEP COPY (ASSIGNMENT) ---" << std::endl;
	
    std::cout << "--- Creating 'cat1' and 'cat2'... ---" << std::endl;
	
    Cat cat1;
    cat1.getBrain()->set_idea(0, "I am cat 1.");
    Cat cat2;
    cat2.getBrain()->set_idea(0, "I am cat 2.");

    std::cout << "--- Assigning 'cat2 = cat1'... ---" << std::endl;
    cat2 = cat1;
    std::cout << "  (Assignment complete. cat2's idea is now: " << cat2.getBrain()->get_idea(0) << ")" << std::endl;

    std::cout << "\n--- Modifying 'original' (cat1)'s brain... ---" << std::endl;
    cat1.getBrain()->set_idea(0, "I am the NEW cat 1.");

    std::cout << "\n--- Checking brains to prove independence... ---" << std::endl;
    std::cout << "  cat1's (original) idea: " << cat1.getBrain()->get_idea(0) << std::endl;
    std::cout << "  cat2's (copy) idea:     " << cat2.getBrain()->get_idea(0) << std::endl;

    // Check if the copy's idea was changed *after* the assignment.
	
    if (cat2.getBrain()->get_idea(0) == "I am cat 1.")
    {
        std::cout << "  (Test PASSED: cat2 is independent. Copy was deep.)" << std::endl;
    }
    else
    {
        std::cout << "  (Test FAILED: cat2's brain was linked to cat1! Copy was shallow.)" << std::endl;
    }

    std::cout << "\n\n--- 4. TEST COMPLETE ---" << std::endl;
    return 0;
}
