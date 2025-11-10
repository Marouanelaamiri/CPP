/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:22:58 by malaamir          #+#    #+#             */
/*   Updated: 2025/11/08 17:16:31 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	// --- Comparison Operators ---
	std::cout << std::boolalpha;
	
	std::cout << "--- COMPARISON TESTS ---" << std::endl;
	Fixed a(10);
	Fixed b(20);

	std::cout << "a = 10, b = 20" << std::endl;
	std::cout << "a > b:  " << (a > b) << std::endl;
	std::cout << "a < b:  " << (a < b) << std::endl;
	std::cout << "a >= b: " << (a >= b) << std::endl;
	std::cout << "a <= b: " << (a <= b) << std::endl;
	std::cout << "a == b: " << (a == b) << std::endl;
	std::cout << "a != b: " << (a != b) << std::endl
			  << std::endl;

	// --- Arithmetic Operators ---
	std::cout << "--- ARITHMETIC TESTS ---" << std::endl;
	Fixed c(10.5f);
	Fixed d(2);

	std::cout << "c = 10.5, d = 2" << std::endl;
	std::cout << "c + d = " << (c + d) << std::endl;
	std::cout << "c - d = " << (c - d) << std::endl;
	std::cout << "c * d = " << (c * d) << std::endl;
	std::cout << "c / d = " << (c / d) << std::endl
			  << std::endl;

	// --- Increment/Decrement Operators ---
	std::cout << "--- INCREMENT/DECREMENT TESTS ---" << std::endl;
	Fixed e; // e is the fixedpointvalue 

	std::cout << "e = " << e << std::endl;
	std::cout << "++e = " << ++e << std::endl; // Pre-increment
	std::cout << "e = " << e << std::endl;
	std::cout << "======================================" << std::endl;
	std::cout << "e++ = " << e++ << std::endl; // Post-increment
	std::cout << "e = " << e << std::endl;
	std::cout << "======================================" << std::endl;
	std::cout << "--e = " << --e << std::endl; // Pre-decrement
	std::cout << "e = " << e << std::endl;
	std::cout << "======================================" << std::endl;
	std::cout << "e-- = " << e-- << std::endl; // Post-decrement
	std::cout << "e = " << e << std::endl
			  << std::endl;

	// --- Min/Max Functions ---
	std::cout << "--- MIN/MAX TESTS ---" << std::endl;
	Fixed f(100);
	Fixed g(100.01f);

	std::cout << "f = 100, g = 100.01" << std::endl;
	std::cout << "Fixed::min(f, g) = " << Fixed::min(f, g) << std::endl;
	std::cout << "Fixed::max(f, g) = " << Fixed::max(f, g) << std::endl
			  << std::endl;

	// Test the const versions
	Fixed const h(50);
	Fixed const i(-50);

	std::cout << "h = 50, i = -50 (const)" << std::endl;
	std::cout << "Fixed::min(h, i) = " << Fixed::min(h, i) << std::endl;
	std::cout << "Fixed::max(h, i) = " << Fixed::max(h, i) << std::endl
			  << std::endl;
	return 0;
}