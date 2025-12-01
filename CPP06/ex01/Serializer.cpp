/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 17:30:55 by malaamir          #+#    #+#             */
/*   Updated: 2025/12/01 17:10:44 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}
Serializer::Serializer(const Serializer &other) { (void)other; }
Serializer &Serializer::operator=(const Serializer &other)
{
	(void(other));
	return *this;
}
Serializer::~Serializer() {}

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);// Interpret the bits of the pointer as an integer
}

// **What happens:**
// ```
// Memory address of Data object: 0x00007FFF12345678

// Data* ptr = 0x00007FFF12345678
//     ↓ reinterpret_cast<uintptr_t>
// uintptr_t num = 140734643724920  (same value, different type)

// Binary representation (64-bit):
// ptr:  [01111111 11111111 00010010 00110100 01010110 01111000] (pointer type)
// num:  [01111111 11111111 00010010 00110100 01010110 01111000] (integer type)
//       ↑ IDENTICAL BITS - no conversion!
	  

// Why uintptr_t?

// Guaranteed to hold any pointer value
// Unsigned (pointers are never negative)
// Platform-specific size (32-bit on 32-bit, 64-bit on 64-bit)

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);// Interpret the bits of the integer as a pointer
}

// **What happens:**
// ```
// uintptr_t num = 140734643724920
//     ↓ reinterpret_cast<Data*>
// Data* ptr = 0x00007FFF12345678  (same address restored)

// Binary:
// num:  [01111111 11111111 00010010 00110100 01010110 01111000] (integer)
// ptr:  [01111111 11111111 00010010 00110100 01010110 01111000] (pointer)
//       ↑ STILL IDENTICAL - just reinterpreted back