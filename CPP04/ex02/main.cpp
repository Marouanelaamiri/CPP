/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:48:39 by malaamir          #+#    #+#             */
/*   Updated: 2025/11/14 17:42:50 by malaamir         ###   ########.fr       */
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
    std::cout << "--- 1. Simple polymorphism test ---" << std::endl;

    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << "---------------------------------" << std::endl;
    
    std::cout << "Pointer 'j' has type: " << j->getType() << " " << std::endl;
    std::cout << "Pointer 'i' has type: " << i->getType() << " " << std::endl;
    
    std::cout << "---------------------------------" << std::endl;

    std::cout << "Pointer 'i' (a Cat) makes sound: ";
    i->makeSound(); 
    std::cout << "Pointer 'j' (a Dog) makes sound: ";
    j->makeSound();
    
    std::cout << "---------------------------------" << std::endl;
    
    std::cout << "Deleting j (Dog)..." << std::endl;
    delete j;
    std::cout << "Deleting i (Cat)..." << std::endl;
    delete i;
    
    std::cout << "\n\n--- 2. TESTING ABSTRACT CLASS ---" << std::endl;

    // Animal test;

    std::cout << "\n--- 3. TEST COMPLETE ---" << std::endl;
    return 0;
}