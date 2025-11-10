/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:18:17 by malaamir          #+#    #+#             */
/*   Updated: 2025/11/08 17:04:46 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed b(a);
	Fixed c;
	a = b;

	// a.setRawBits(42);
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return 0;
}

// it does return 0 always because the fixedpointvalue is initialized to 0 in the default constructor and never changed.
// the copy constructor and copy assignment operator just copy this value, which is still 0.
// if we change the fixedpoint value to something else like(42) using setRawbits the output will change.