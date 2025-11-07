/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:24:36 by malaamir          #+#    #+#             */
/*   Updated: 2025/11/07 18:56:06 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
class Fixed
{
private:
	int fixedpointvalue;
	static const int fractionalbits;

public: // Canonical form
	Fixed();
	Fixed(const Fixed &other);			  // Copy constructor
	Fixed &operator=(const Fixed &other); // Copy assignment operator
	~Fixed();

	Fixed(const int intValue);	   // Constructor that takes an integer
	Fixed(const float floatValue); // Constructor that takes a float
	int toInt(void) const;		   // Converts the fixed-point value to an integer value
	float toFloat(void) const;	   // Converts the fixed-point value to a float value

	int getRawBits(void) const;
	void setRawBits(int const raw);

	// Comparison operators
	bool operator>(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;

	// Arithmetic operators
	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;

	// Increment and Decrement operators
	Fixed &operator++();   // Prefix increment
	Fixed operator++(int); // Postfix increment
	Fixed &operator--();   // Prefix decrement
	Fixed operator--(int); // Postfix decrement

	// Static member functions for min and max
	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed); // Overload the insertion operator for easy output

#endif