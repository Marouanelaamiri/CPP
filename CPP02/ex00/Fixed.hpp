/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:18:31 by malaamir          #+#    #+#             */
/*   Updated: 2025/11/06 11:45:12 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
class Fixed
{
private:
	int                 fixedpointvalue;
	static const int    fractionalbits; 
public: // Canonical form
	Fixed();
	Fixed(const Fixed &other);// Copy constructor
	Fixed &operator=(const Fixed &other);// Copy assignment operator
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};
#endif