/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamiri <malaamiri@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 18:25:55 by malaamiri         #+#    #+#             */
/*   Updated: 2025/12/13 18:28:43 by malaamiri        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

// TEST FUNCTION 1: Takes Non-Const Reference (Modifies the value)
void addOne(int &n) {
    n += 1;
}

// TEST FUNCTION 2: Takes Const Reference (Only reads the value)
void printInt(const int &n) {
    std::cout << n << " ";
}

int main() {
    std::cout << "=== TEST 1: Int Array (Modification) ===" << std::endl;
    int arr[] = {1, 2, 3, 4, 5};
    
    std::cout << "Original: ";
    ::iter(arr, 5, printInt); // Context: Mutable array, Read-only function
    std::cout << std::endl;

    // Apply modification
    ::iter(arr, 5, addOne);   // Context: Mutable array, Modifying function

    std::cout << "Modified: ";
    ::iter(arr, 5, printInt);
    std::cout << std::endl;


    std::cout << "\n=== TEST 2: Const Int Array (Read-Only) ===" << std::endl;
    const int c_arr[] = {10, 20, 30};

    std::cout << "Values: ";
    // Context: Const array, Read-only function
    // If your template was wrong, this line would fail to compile.
    ::iter(c_arr, 3, printInt); 
    
    // Uncommenting the line below should cause a compilation error (Good!)
    // ::iter(c_arr, 3, addOne); 
    std::cout << std::endl;

    return 0;
}