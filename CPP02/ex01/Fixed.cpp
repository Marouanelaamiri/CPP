/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:24:46 by malaamir          #+#    #+#             */
/*   Updated: 2025/11/07 18:56:17 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractionalbits = 8; // scaling factor of 2^8 = 256
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

Fixed::Fixed(const int intValue) // Constructor that takes an integer , converts it to fixed-point representation
{
	std::cout << "Int constructor called" << std::endl;
	fixedpointvalue = intValue << fractionalbits; // or intValue * fractionalbits
}

Fixed::Fixed(const float floatValue) // Constructor that takes a float , converts it to fixed-point representation
{
	std::cout << "Float constructor called" << std::endl;
	fixedpointvalue = roundf(floatValue * (1 << fractionalbits)); // or (1 << fractionalbits)
}

int Fixed::toInt(void) const // Converts the fixed-point value to an integer value
{
	return fixedpointvalue >> fractionalbits; // or fixedpointvalue / fractionalbits
}

float Fixed::toFloat(void) const // Converts the fixed-point value to a floating-point value
{
	return (float)(fixedpointvalue) / (1 << fractionalbits); // fixedpoint / 2 ^ 8
}

// this is an ad-hoc ,we r teaching the compiler how to output our Fixed objects when we use cout
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) // Overload the insertion operator for easy output
{
	out << fixed.toFloat();
	return out;
}
