/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 17:17:54 by malaamiri         #+#    #+#             */
/*   Updated: 2025/12/18 17:03:01 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"


int main(void)
{
	int a = 2;
	int b = 3;
	std::cout << "Initial values:" << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	// we are using :: to ensure we use OUR swap, not std::swap
	::swap(a, b);
	std::cout << "After swap:" << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
	std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";
	std::cout << "Initial values:" << std::endl;
	std::cout << "c = " << c << ", d = " << d << std::endl;
	::swap(c, d);
	std::cout << "After swap:" << std::endl;
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
	std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

	float e = 4.2f;
	float f = 2.4f;
	std::cout << "Initial values:" << std::endl;
	std::cout << "e =" << e << ", f = " << f << std::endl;
	::swap(e, f);
	std::cout << "After swap:" << std::endl;
	std::cout << "e =" << e << ", f = " << f << std::endl;
	std::cout << "min( e, f ) = " << ::min(e, f) << std::endl;
	std::cout << "max( e, f ) = " << ::max(e, f) << std::endl;

	return 0;
}