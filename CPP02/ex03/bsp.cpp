/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 19:22:27 by malaamir          #+#    #+#             */
/*   Updated: 2025/11/08 21:23:54 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed getside(Point const p1, Point const p2, Point const point)
{
	Fixed left = (point.getX() - p1.getX()) * (p2.getY() - p1.getY());
	Fixed right = (point.getY() - p1.getY()) * (p2.getX() - p1.getX());

	return (left - right);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed sideAB = getside(a, b, point);
	Fixed sideBC = getside(b, c, point);
	Fixed sideCA = getside(c, a, point);

	bool positive = (sideAB > 0) && (sideBC > 0) && (sideCA > 0);
	bool negative = (sideAB < 0) && (sideBC < 0) && (sideCA < 0);

	return (positive || negative);
}
