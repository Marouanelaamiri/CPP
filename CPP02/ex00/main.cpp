/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:18:17 by malaamir          #+#    #+#             */
/*   Updated: 2025/11/06 18:00:20 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed a; // Default constructor
	Fixed b(a); // Copy constructor
	Fixed c; // Default constructor
	a = b; // Copy assignment operator
	
	a.setRawBits(42); // setRawBits member function
	std::cout << a.getRawBits() << std::endl; // getRawBits member function
	std::cout << b.getRawBits() << std::endl; // getRawBits member function
	std::cout << c.getRawBits() << std::endl; // getRawBits member function
	
	return 0;
}
 // it does return 0 always because the fixedpointvalue is initialized to 0 in the default constructor and never changed.
 // the copy constructor and copy assignment operator just copy this value, which is still 0.
  // we can change the fixedpointvalue using the setRawBits member function, but in this main function, we never do that.