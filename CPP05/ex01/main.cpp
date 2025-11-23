/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:34:03 by malaamir          #+#    #+#             */
/*   Updated: 2025/11/22 20:01:57 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat b("Alice", 50);
		Form f("TopSecret", 1, 151);

		std::cout << b << std::endl;
		std::cout << f << std::endl;

		b.signForm(f);
		std::cout << f << std::endl;

		Bureaucrat c("Bob", 1337);
		c.signForm(f); // This should throw an exception
	}
	catch (const std::exception &e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	return 0;
}