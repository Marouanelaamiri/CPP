/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:42:18 by malaamir          #+#    #+#             */
/*   Updated: 2025/12/18 17:16:13 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
	std::cout << "Basic tests" << std::endl;

	Array<int> a(5);
	for (unsigned int i = 0; i < a.size(); i++)
		a[i] = i * 10;

	std::cout << "Array a contents:" << std::endl;
	for (unsigned int i = 0; i < a.size(); i++)
		std::cout << "a[" << i << "] = " << a[i] << std::endl;

	std::cout << "\nCopy constructor" << std::endl;
	Array<int> b(a);

	std::cout << "Array b contents (copy of a):" << std::endl;
	for (unsigned int i = 0; i < b.size(); i++)
		std::cout << "b[" << i << "] = " << b[i] << std::endl;

	std::cout << "\nAssignment operator" << std::endl;
	Array<int> c;
	c = a;

	std::cout << "Array c contents (copy of a):" << std::endl;
	for (unsigned int i = 0; i < c.size(); i++)
		std::cout << "c[" << i << "] = " << c[i] << std::endl;

	std::cout << "\n---- Bounds checking ----" << std::endl;
	try
	{
		std::cout << a[99] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n---- String Array ----" << std::endl;
	Array<std::string> s(3);
	s[0] = "Hello";
	s[1] = "World";
	s[2] = "!!";

	for (unsigned int i = 0; i < s.size(); i++)
		std::cout << "s[" << i << "] = " << s[i] << std::endl;

	return 0;
}
