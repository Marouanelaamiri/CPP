/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 21:33:30 by malaamir          #+#    #+#             */
/*   Updated: 2025/10/30 21:41:48 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string brain = "HI THIS IS BRAIN";
	std::string* stringPTR = &brain;
	std::string& stringREF = brain;

	std::cout << "Address of brain: " << &brain << std::endl;
	
	std::cout << "stringREF Address: " << &stringREF << std::endl;
	std::cout << "stringPTR Address: " << stringPTR << std::endl;

	std::cout << "Value referred to by stringREF: " << stringREF << std::endl;
	std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;

	return 0;
}