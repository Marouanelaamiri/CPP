/*	 ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 17:26:54 by malaamir          #+#    #+#             */
/*   Updated: 2025/11/30 17:28:00 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>	 // rand, srand
#include <ctime>	 // time
#include <exception> // std::exception

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
	int i = std::rand() % 3;

	if (i == 0)
	{
		std::cout << "Generated: A" << std::endl;
		return new class A();
	}
	else if (i == 1)
	{
		std::cout << "Generated: B" << std::endl;
		return new class B();
	}
	else
	{
		std::cout << "Generated: C" << std::endl;
		return new class C();
	}
}