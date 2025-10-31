/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 21:33:30 by malaamir          #+#    #+#             */
/*   Updated: 2025/10/31 14:36:01 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string brain = "HI THIS IS BRAIN";
	std::string* stringPTR = &brain; // actual pointer to brain // pointer can be declared without initialization
	std::string& stringREF = brain; // alias reference to brain // reference must be initialized when declared

	std::cout << "Address of brain: " << &brain << std::endl;
	
	std::cout << "stringREF Address: " << &stringREF << std::endl;
	std::cout << "stringPTR Address: " << stringPTR << std::endl;

	std::cout << "Value referred to by stringREF: " << stringREF << std::endl;// dereferencing the reference
	std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl; // dereferencing the pointer

	return 0;
}