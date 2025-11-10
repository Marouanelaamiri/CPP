/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 19:20:11 by malaamir          #+#    #+#             */
/*   Updated: 2025/11/08 21:23:15 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void)
{

	Point a(0, 0);
	Point b(10, 0);
	Point c(0, 10);
	Point p(3, 3);

	if (bsp(a, b, c, p))
		std::cout << "it's inside the triangle" << std::endl;
	else
		std::cout << "it's Outside the triangle, or on the edge or on vertex" << std::endl;
}