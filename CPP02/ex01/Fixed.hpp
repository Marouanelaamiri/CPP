/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:24:36 by malaamir          #+#    #+#             */
/*   Updated: 2025/11/07 18:58:07 by malaamir         ###   ########.fr       */
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

	int getRawBits(void) const;
	void setRawBits(int const raw);

	float toFloat(void) const; // Converts the fixed-point value to a floating-point value
	int toInt(void) const;	   // Converts the fixed-point value to an integer value
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed); // Overload the insertion operator for easy output

#endif