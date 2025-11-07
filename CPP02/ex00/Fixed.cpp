/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:18:43 by malaamir          #+#    #+#             */
/*   Updated: 2025/11/07 18:58:19 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractionalbits = 8; // its 8 bits for the fractional part because its a common choice that provides a good balance between range and precision for many applications.

Fixed::Fixed() : fixedpointvalue(0) { std::cout << "Default constructor called" << std::endl; }

Fixed::Fixed(const Fixed &other) // Copy constructor
{
	std::cout << "Copy constructor called" << std::endl;
	this->fixedpointvalue = other.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &other) // Copy assignment operator
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->fixedpointvalue = other.getRawBits(); // to avoid self-assignment
	return *this;									// return the current object , a = b; we return the last assigned object (b in this case) to allow chaining assignments.
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->fixedpointvalue;
}
void Fixed::setRawBits(int const raw) { this->fixedpointvalue = raw; }
