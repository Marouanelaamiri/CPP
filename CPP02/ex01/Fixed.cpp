/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:24:46 by malaamir          #+#    #+#             */
/*   Updated: 2025/11/08 17:22:37 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractionalbits = 8;
Fixed::Fixed() : fixedpointvalue(0) { std::cout << "Default constructor called" << std::endl; }

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->fixedpointvalue = other.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->fixedpointvalue = other.getRawBits();
	return *this;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->fixedpointvalue;
}
void Fixed::setRawBits(int const raw) { this->fixedpointvalue = raw; }

Fixed::Fixed(const int intValue)
{
	std::cout << "Int constructor called" << std::endl;
	fixedpointvalue = intValue * (1 << fractionalbits);
}

Fixed::Fixed(const float floatValue)
{
	std::cout << "Float constructor called" << std::endl;
	fixedpointvalue = roundf(floatValue * (1 << fractionalbits));
}

int Fixed::toInt(void) const
{
	return fixedpointvalue / (1 << fractionalbits);
}

float Fixed::toFloat(void) const
{
	return (float)(fixedpointvalue) / (1 << fractionalbits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}
