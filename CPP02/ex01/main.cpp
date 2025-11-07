/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:22:58 by malaamir          #+#    #+#             */
/*   Updated: 2025/11/07 18:56:22 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed a;			   // Default constructor called here
	Fixed const b(10);	   // Int constructor called here
	Fixed const c(42.42f); // Float constructor called here
	Fixed const d(b);	   // Copy constructor called here

	a = Fixed(1234.4321f); // Assignment operator called here

	std::cout << "a is " << a << std::endl; // uses the overloaded << operator
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl; // toInt member function called here
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return 0;
}