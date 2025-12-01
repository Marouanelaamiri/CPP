/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 17:47:56 by malaamir          #+#    #+#             */
/*   Updated: 2025/12/01 17:12:04 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"


int main() {
    // Create original data
    Data* original = new Data();
    original->value = 42;
    original->name = "test";
    
    std::cout << "Original pointer: " << original << std::endl;
    std::cout << "Original value: " << original->value << std::endl;
    
    // Serialize: pointer → integer
    uintptr_t serialized = Serializer::serialize(original);
    std::cout << "Serialized: " << serialized << std::endl;
    
    // Deserialize: integer → pointer
    Data* deserialized = Serializer::deserialize(serialized);
    std::cout << "Deserialized pointer: " << deserialized << std::endl;
    std::cout << "Deserialized value: " << deserialized->value << std::endl;
    
    // Check if pointers match
    if (original == deserialized) {
        std::cout << "SUCCESS: Pointers match!" << std::endl;
    }
    
    delete original;
    return 0;
}

// **Output:**

// Original pointer: 0x7fff12345678
// Original value: 42
// Serialized: 140734643724920
// Deserialized pointer: 0x7fff12345678
// Deserialized value: 42
// SUCCESS: Pointers match!