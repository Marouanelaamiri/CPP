/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:24:46 by malaamir          #+#    #+#             */
/*   Updated: 2025/11/07 18:53:56 by malaamir         ###   ########.fr       */
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

// Comparison operators
bool Fixed::operator>(const Fixed &other) const
{
	return this->fixedpointvalue > other.getRawBits();
}
bool Fixed::operator<(const Fixed &other) const
{
	return this->fixedpointvalue < other.getRawBits();
}
bool Fixed::operator>=(const Fixed &other) const
{
	return this->fixedpointvalue >= other.getRawBits();
}
bool Fixed::operator<=(const Fixed &other) const
{
	return this->fixedpointvalue <= other.getRawBits();
}
bool Fixed::operator==(const Fixed &other) const
{
	return this->fixedpointvalue == other.getRawBits();
}
bool Fixed::operator!=(const Fixed &other) const
{
	return this->fixedpointvalue != other.getRawBits();
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed &other) const
{
	float val1 = this->toFloat();
	float val2 = other.toFloat();

	return Fixed(val1 + val2);
}
Fixed Fixed::operator-(const Fixed &other) const
{
	float val1 = this->toFloat();
	float val2 = other.toFloat();

	return Fixed(val1 - val2);
}
Fixed Fixed::operator*(const Fixed &other) const
{
	float val1 = this->toFloat();
	float val2 = other.toFloat();

	return Fixed(val1 * val2);
}
Fixed Fixed::operator/(const Fixed &other) const
{
	float val1 = this->toFloat();
	float val2 = other.toFloat();

	return Fixed(val1 / val2);
}

// Increment and Decrement operators
Fixed &Fixed::operator++()
{
	this->fixedpointvalue = this->fixedpointvalue + 1;
	return *this;
}
Fixed Fixed::operator++(int) // int is a dummy , just to make diffrence bwtween this funcion and the above one
{
	Fixed copy(*this); // copy constructor
	this->fixedpointvalue = this->fixedpointvalue + 1;
	return copy;
}
Fixed &Fixed::operator--()
{
	this->fixedpointvalue = this->fixedpointvalue - 1;
	return *this;
}
Fixed Fixed::operator--(int)
{
	Fixed copy(*this); // copy constructor
	this->fixedpointvalue = this->fixedpointvalue - 1;
	return copy;
}

// Static member functions for min and max

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return a;
	else
		return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return a;
	else
		return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return a;
	else
		return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return a;
	else
		return b;
}
