/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:24:46 by malaamir          #+#    #+#             */
/*   Updated: 2025/11/08 20:34:51 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractionalbits = 8;
Fixed::Fixed() : fixedpointvalue(0) {}

Fixed::Fixed(const Fixed &other)
{
	this->fixedpointvalue = other.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->fixedpointvalue = other.getRawBits();
	return *this;
}

Fixed::~Fixed() {}

int Fixed::getRawBits(void) const
{
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

Fixed &Fixed::operator++()
{
	this->fixedpointvalue += 1;
	return *this;
}
Fixed Fixed::operator++(int)
{
	Fixed copy(*this);
	this->fixedpointvalue += 1;
	return copy;
}
Fixed &Fixed::operator--()
{
	this->fixedpointvalue -= 1;
	return *this;
}
Fixed Fixed::operator--(int)
{
	Fixed copy(*this);
	this->fixedpointvalue -= 1;
	return copy;
}

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
