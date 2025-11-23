/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:34:03 by malaamir          #+#    #+#             */
/*   Updated: 2025/11/22 19:02:06 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat b("John", 50);
		std::cout << b << std::endl;

		b.incrementGrade();
		std::cout << b << std::endl;

		b.decrementGrade();
		std::cout << b << std::endl;

		Bureaucrat c("Doe", 150);
		std::cout << c << std::endl;

		c.incrementGrade();
		std::cout << c << std::endl;

		c.decrementGrade();
		std::cout << c << std::endl;

		c.decrementGrade(); // This should throw an exception
		std::cout << c << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}